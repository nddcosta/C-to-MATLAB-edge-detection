function build(target)

    entryPoint = 'edgeDetection';
    im = zeros(259, 460, 'double');
    imsize = int32(size(im));
    output = zeros(size(im), 'like', im);
    
    cfg = coder.config(target);
    cfg.CustomSource = 'edge_detection.c';
    cfg.CustomSourceCode = ['#include "edge_detection.h"'];
    
    cfg.GenerateReport = true;
    cfg.LaunchReport = false;
    
    codegen(entryPoint, '-args', {im, imsize}, '-config', cfg);
end
    