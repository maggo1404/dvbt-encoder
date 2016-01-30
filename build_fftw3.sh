apt-get source libfftw3-dev
cd fftw3-3.3.3
./configure --enable-static --enable-single --enable-threads --with-pic
make -j4
