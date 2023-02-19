# Run length code in OPenCV
 Implementing RLC on images in OpenCV

Run Length Code (RLC) is a compact way of encoding images for storage and transmission. The
idea is to use the redundancy in pixel value information among neighboring pixels in order to
reduce amount of information to be stored. The algorithm proceeds row wise and stores indexes
of columns of contagious segments of same pixel value.

The algorithm implements RLC. It uses LinkedList to store the image in RLC computed images. 