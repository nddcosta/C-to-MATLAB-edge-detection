function y = edgeDetection(x, imsize)
    y = coder.nullcopy(zeros(259, 460));
    
    if coder.target('MEX')
        coder.updateBuildInfo('addSourceFiles', 'edge_detection.c');
        fprintf('Running custom edge detection code...\n\n');
        coder.ceval('edge_detection', coder.ref(x), coder.ref(imsize), coder.ref(y));
    end
end