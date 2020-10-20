%% Edge detection using custom C code
% Using mex functions, custom C code can be written and then used in MATLAB

%% Import image
img = imread('butterfly.jpg');
imshow(img, []);

%% Convert image to gray scale
grayImg = rgb2gray(img);
im = double(grayImg);
imshow(im, []);

%% Call custom C sobel edge detection code
imsize = int32(size(im));
C_edgeDetectedImg = edgeDetection_mex(im, imsize);
imshow(C_edgeDetectedImg, []);

%% Threshold image
threshImg = C_edgeDetectedImg > 240;
imshow(threshImg, []);
