#ifndef simnoise_HEADER
#define simnoise_HEADER

/// returns a 3d vector, given a 4d position + time vector
/**
   given a "plane" it can return different values - this is handy, for example
   when combining into a fractal and you want to avoid the singularity that always
   occurs at the origin of the fractal space.
**/
void simnoise3dtX( float V[3], const float P[4], unsigned char uPlane );

/// returns a 3d vector, given a 4d position + time vector
void simnoise3dt( float V[3], const float P[4] );

void simnoise3d( float V[3], const float P[3] );

#endif
