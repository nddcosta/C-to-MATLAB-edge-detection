<!DOCTYPE html
  PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head>
      <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
   <!--
This HTML was auto-generated from MATLAB code.
To make changes, update the MATLAB code and republish this document.
      --><title>Edge detection using custom C code</title><meta name="generator" content="MATLAB 9.7"><link rel="schema.DC" href="http://purl.org/dc/elements/1.1/"><meta name="DC.date" content="2020-10-20"><meta name="DC.source" content="test.m"><style type="text/css">
html,body,div,span,applet,object,iframe,h1,h2,h3,h4,h5,h6,p,blockquote,pre,a,abbr,acronym,address,big,cite,code,del,dfn,em,font,img,ins,kbd,q,s,samp,small,strike,strong,sub,sup,tt,var,b,u,i,center,dl,dt,dd,ol,ul,li,fieldset,form,label,legend,table,caption,tbody,tfoot,thead,tr,th,td{margin:0;padding:0;border:0;outline:0;font-size:100%;vertical-align:baseline;background:transparent}body{line-height:1}ol,ul{list-style:none}blockquote,q{quotes:none}blockquote:before,blockquote:after,q:before,q:after{content:'';content:none}:focus{outine:0}ins{text-decoration:none}del{text-decoration:line-through}table{border-collapse:collapse;border-spacing:0}

html { min-height:100%; margin-bottom:1px; }
html body { height:100%; margin:0px; font-family:Arial, Helvetica, sans-serif; font-size:10px; color:#000; line-height:140%; background:#fff none; overflow-y:scroll; }
html body td { vertical-align:top; text-align:left; }

h1 { padding:0px; margin:0px 0px 25px; font-family:Arial, Helvetica, sans-serif; font-size:1.5em; color:#d55000; line-height:100%; font-weight:normal; }
h2 { padding:0px; margin:0px 0px 8px; font-family:Arial, Helvetica, sans-serif; font-size:1.2em; color:#000; font-weight:bold; line-height:140%; border-bottom:1px solid #d6d4d4; display:block; }
h3 { padding:0px; margin:0px 0px 5px; font-family:Arial, Helvetica, sans-serif; font-size:1.1em; color:#000; font-weight:bold; line-height:140%; }

a { color:#005fce; text-decoration:none; }
a:hover { color:#005fce; text-decoration:underline; }
a:visited { color:#004aa0; text-decoration:none; }

p { padding:0px; margin:0px 0px 20px; }
img { padding:0px; margin:0px 0px 20px; border:none; }
p img, pre img, tt img, li img, h1 img, h2 img { margin-bottom:0px; } 

ul { padding:0px; margin:0px 0px 20px 23px; list-style:square; }
ul li { padding:0px; margin:0px 0px 7px 0px; }
ul li ul { padding:5px 0px 0px; margin:0px 0px 7px 23px; }
ul li ol li { list-style:decimal; }
ol { padding:0px; margin:0px 0px 20px 0px; list-style:decimal; }
ol li { padding:0px; margin:0px 0px 7px 23px; list-style-type:decimal; }
ol li ol { padding:5px 0px 0px; margin:0px 0px 7px 0px; }
ol li ol li { list-style-type:lower-alpha; }
ol li ul { padding-top:7px; }
ol li ul li { list-style:square; }

.content { font-size:1.2em; line-height:140%; padding: 20px; }

pre, code { font-size:12px; }
tt { font-size: 1.2em; }
pre { margin:0px 0px 20px; }
pre.codeinput { padding:10px; border:1px solid #d3d3d3; background:#f7f7f7; }
pre.codeoutput { padding:10px 11px; margin:0px 0px 20px; color:#4c4c4c; }
pre.error { color:red; }

@media print { pre.codeinput, pre.codeoutput { word-wrap:break-word; width:100%; } }

span.keyword { color:#0000FF }
span.comment { color:#228B22 }
span.string { color:#A020F0 }
span.untermstring { color:#B20000 }
span.syscmd { color:#B28C00 }

.footer { width:auto; padding:10px 0px; margin:25px 0px 0px; border-top:1px dotted #878787; font-size:0.8em; line-height:140%; font-style:italic; color:#878787; text-align:left; float:none; }
.footer p { margin:0px; }
.footer a { color:#878787; }
.footer a:hover { color:#878787; text-decoration:underline; }
.footer a:visited { color:#878787; }

table th { padding:7px 5px; text-align:left; vertical-align:middle; border: 1px solid #d6d4d4; font-weight:bold; }
table td { padding:7px 5px; text-align:left; vertical-align:top; border:1px solid #d6d4d4; }





  </style></head><body><div class="content"><h1>Edge detection using custom C code</h1><!--introduction--><p>Using mex functions, custom C code can be written and then used in MATLAB</p><!--/introduction--><h2>Contents</h2><div><ul><li><a href="#1">Import image</a></li><li><a href="#2">Convert image to gray scale</a></li><li><a href="#3">Call custom C sobel edge detection code</a></li><li><a href="#4">Threshold image</a></li></ul></div><h2 id="1">Import image</h2><pre class="codeinput">img = imread(<span class="string">'butterfly.jpg'</span>);
imshow(img, []);
</pre><img vspace="5" hspace="5" src="test_01.png" alt=""> <h2 id="2">Convert image to gray scale</h2><pre class="codeinput">grayImg = rgb2gray(img);
im = double(grayImg);
imshow(im, []);
</pre><img vspace="5" hspace="5" src="test_02.png" alt=""> <h2 id="3">Call custom C sobel edge detection code</h2><pre class="codeinput">imsize = int32(size(im));
C_edgeDetectedImg = edgeDetection_mex(im, imsize);
imshow(C_edgeDetectedImg, []);
</pre><pre class="codeoutput">Running custom edge detection code...

</pre><img vspace="5" hspace="5" src="test_03.png" alt=""> <h2 id="4">Threshold image</h2><pre class="codeinput">threshImg = C_edgeDetectedImg &gt; 240;
imshow(threshImg, []);
</pre><img vspace="5" hspace="5" src="test_04.png" alt=""> <p class="footer"><br><a href="https://www.mathworks.com/products/matlab/">Published with MATLAB&reg; R2019b</a><br></p></div><!--
##### SOURCE BEGIN #####
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
##### SOURCE END #####
--></body></html>
