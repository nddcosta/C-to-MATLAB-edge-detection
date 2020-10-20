<!DOCTYPE html
<body><div class="content"><h1>Edge detection using custom C code</h1><!--introduction--><p>Using mex functions, custom C code can be written and then used in MATLAB</p><!--/introduction--><h2>Contents</h2><div><ul><li><a href="#1">Import image</a></li><li><a href="#2">Convert image to gray scale</a></li><li><a href="#3">Call custom C sobel edge detection code</a></li><li><a href="#4">Threshold image</a></li></ul></div><h2 id="1">Import image</h2><pre class="codeinput">img = imread(<span class="string">'butterfly.jpg'</span>);
imshow(img, []);
</pre><img vspace="5" hspace="5" src="html/test_01.png" alt=""> <h2 id="2">Convert image to gray scale</h2><pre class="codeinput">grayImg = rgb2gray(img);
im = double(grayImg);
imshow(im, []);
</pre><img vspace="5" hspace="5" src="html/test_02.png" alt=""> <h2 id="3">Call custom C sobel edge detection code</h2><pre class="codeinput">imsize = int32(size(im));
C_edgeDetectedImg = edgeDetection_mex(im, imsize);
imshow(C_edgeDetectedImg, []);
</pre><pre class="codeoutput">Running custom edge detection code...

</pre><img vspace="5" hspace="5" src="html/test_03.png" alt=""> <h2 id="4">Threshold image</h2><pre class="codeinput">threshImg = C_edgeDetectedImg &gt; 240;
imshow(threshImg, []);
</pre><img vspace="5" hspace="5" src="/htmltest_04.png" alt=""> <p class="footer"><br><a href="https://www.mathworks.com/products/matlab/">Published with MATLAB&reg; R2019b</a><br></p></div>
</body></html>
