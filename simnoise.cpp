#include "simnoise.h"

const unsigned char _cpTable[256] = {
 64,178,249,199, 77,243,127, 12,240, 52,220,219,193,112,143,205,
 93,169,152,192,225, 85,109,171, 83,124,148, 53,186,251, 82,166,
 69, 51,180, 79,  4,217,247,115,226,113,101,191,131,252,  2,231,
239,190, 73,232,229, 76,250, 29,164, 18,161, 71, 91,121,139,145,
 74, 19,153,130,246,253, 15, 59, 36, 47, 54,147, 24,197, 26, 17,
141,187, 89,203, 10,210,201, 95, 21, 25,128,104,150,214,  3, 42,
 46, 39,244,163, 81, 50,160, 48,218, 45,196,157,  9,207,234,206,
135,132, 65,114,200,216, 88,110,134,211,254, 14, 20,227,184, 61,
237,107, 57,137,154,245,208,228,189, 43, 56, 37, 92,102,182,108,
 98, 96, 44,  6,233,172,242,215, 32,194,198,173,230,255,202,236,
 35, 94, 70,103, 66,126, 87,221, 28, 84,212,174,122,235,175,185,
138,167,146, 60, 27,241, 97, 38, 33,213, 22,156,  1,195,176,223,
224, 62,151,162,  8, 90, 34,144, 58,  7, 86, 13,248, 68,183,  0,
119,158,125, 99, 49,  5, 11, 55,168,209, 30,188,136,120, 41,238,
118,100,204,105,142, 67, 78,159,140, 72,117,179, 63,149,129, 40,
170,106,177,123, 23, 31,133, 75,181,111, 80, 16,222,155,165,116
};

const unsigned short _spTable[256] = {
0x37f9,0x24c8,0x4613,0x5d0e,0x2953,0x7baa,0x4fc0,0x73d3,
0x724e,0x3c58,0x2984,0x7c4c,0x2760,0x7cc7,0x0a3d,0x0681,
0x434e,0x7d65,0x145b,0x4c1c,0x2475,0x5cdd,0x3494,0x1e40,
0x7916,0x51f1,0x28e1,0x6984,0x55d8,0x0db8,0x54b4,0x2635,
0x2ed8,0x23f3,0x4361,0x0df0,0x59ab,0x32d1,0x2cb2,0x7639,
0x57d0,0x70a5,0x6ca6,0x048a,0x2808,0x1874,0x34b7,0x4e29,
0x4e47,0x1b08,0x7908,0x3f34,0x159d,0x3973,0x1bc0,0x0c4c,
0x3f52,0x7dba,0x49e6,0x5a58,0x7b3b,0x2f97,0x1634,0x2a5e,
0x743d,0x3890,0x2e0d,0x00c1,0x2840,0x58fa,0x5801,0x4598,
0x548e,0x198b,0x091a,0x433f,0x381b,0x5e65,0x622f,0x0953,
0x7d83,0x4568,0x4c8d,0x3c84,0x78dc,0x6672,0x6e17,0x4653,
0x34f2,0x0049,0x6c2b,0x2852,0x7cd2,0x0ed2,0x03aa,0x6356,
0x2360,0x4dce,0x12d1,0x1099,0x707c,0x5bb2,0x2c72,0x3397,
0x5364,0x614f,0x130d,0x1b63,0x57a6,0x5f3e,0x54e4,0x452b,
0x7f80,0x167e,0x1ee3,0x4363,0x5a96,0x0d7c,0x56ee,0x03f4,
0x6348,0x556c,0x0bf4,0x2e8e,0x3d22,0x2ca1,0x5d3f,0x7033,
0x1cb4,0x7f2f,0x65ae,0x7f72,0x111b,0x1822,0x759c,0x4d27,
0x7521,0x3b54,0x3c8c,0x46f6,0x5160,0x6071,0x048a,0x143a,
0x619f,0x3708,0x03d8,0x0f2e,0x51f1,0x40e2,0x70fa,0x3433,
0x0bd0,0x6b52,0x6b20,0x7607,0x3425,0x5f2d,0x70f2,0x0ddb,
0x750a,0x7a86,0x2a9e,0x26b3,0x4663,0x1aae,0x1221,0x4395,
0x4a89,0x720e,0x272b,0x7a9a,0x2a57,0x74a3,0x7189,0x045e,
0x272f,0x7d35,0x25fd,0x5a25,0x2a07,0x2c59,0x033e,0x693d,
0x035c,0x555d,0x5588,0x4af9,0x08f8,0x3cfb,0x71b1,0x356e,
0x5cc7,0x5dbb,0x3049,0x3a4c,0x61e2,0x6190,0x77e8,0x72c4,
0x71f1,0x01a4,0x276f,0x32f6,0x6afd,0x076c,0x21a9,0x1e1c,
0x2eaf,0x68e8,0x1f36,0x7ec3,0x36ce,0x6e98,0x09d9,0x0881,
0x6f2b,0x27f9,0x7f16,0x54a1,0x79e8,0x7e25,0x62f0,0x0cb8,
0x536a,0x784e,0x460d,0x5e7c,0x41e3,0x4df2,0x67d7,0x081b,
0x5743,0x1544,0x1fd5,0x329a,0x6985,0x59d6,0x5e6f,0x2686,
0x1ad0,0x54ca,0x7728,0x183d,0x6203,0x1cde,0x217d,0x2ea4,
0x30c0,0x21bd,0x6b6a,0x1d55,0x0515,0x3603,0x17fa,0x7ee0
};

#define FASTFLOOR(x) ( ((x)>0) ? ((int)x) : (((int)x)-1) )

// returns values in range [-15.5,15.5]
void hash4dX( float V[3], signed long x, signed long y, signed long z, signed long t, unsigned char uPlane )
{
  unsigned short s = _spTable[ _cpTable[ (x & 0xff) ^ _cpTable[ (y & 0xff) ^ _cpTable[ (z & 0xff) ^ _cpTable[ (t & 0xff) ^ _cpTable[uPlane] ]]]]];

  V[0] = float(s & 0x1f);
  s >>= 5;
  V[1] = float(s & 0x1f);
  s >>= 5;
  V[2] = float(s & 0x1f);

  V[0] -= 15.5F;
  V[1] -= 15.5F;
  V[2] -= 15.5F;

  return;
}


// returns values in range [-15.5,15.5]
void hash4d( float V[3], signed long x, signed long y, signed long z, signed long t )
{
  unsigned short s = _spTable[ _cpTable[ (x & 0xff) ^ _cpTable[ (y & 0xff) ^ _cpTable[ (z & 0xff) ^ _cpTable[ t & 0xff ]]]]];

  V[0] = float(s & 0x1f);
  s >>= 5;
  V[1] = float(s & 0x1f);
  s >>= 5;
  V[2] = float(s & 0x1f);

  V[0] -= 15.5F;
  V[1] -= 15.5F;
  V[2] -= 15.5F;

  return;
}

// returns values in range [-15.5,15.5]
void hash3d( float V[3], signed long x, signed long y, signed long z )
{
  unsigned short s = _spTable[ _cpTable[ (x & 0xff) ^ _cpTable[ (y & 0xff) ^ _cpTable[ (z & 0xff) ]]]];

  V[0] = float(s & 0x1f);
  s >>= 5;
  V[1] = float(s & 0x1f);
  s >>= 5;
  V[2] = float(s & 0x1f);

  V[0] -= 15.5F;
  V[1] -= 15.5F;
  V[2] -= 15.5F;

  return;
}

// returns values in range [-15.5,15.5]
void hash2d( float V[2], unsigned long x, unsigned long y )
{
  unsigned short s = _spTable[ _cpTable[ (x & 0xff) ^ _cpTable[ (y & 0xff) ]]];

  V[0] = float(s & 0x1f);
  s >>= 5;
  V[1] = float(s & 0x1f);
  s >>= 5;

  V[0] -= 15.5F;
  V[1] -= 15.5F;

  return;
}


inline float step( float x )
{ return (x * x * x) * ( 10.0F + x * ( 6.0F * x - 15.0F )); }


inline float bell( float x )
{ return (16.0F * x * x) * ( 1.0F + x * ( x - 2.0F )); }


inline float mix( float a, float b, float x )
{ return a + (b-a)*x; }


/// returns V[3] in range +/- 15.5
inline void noise3dt( float V[3], signed long Pi[3], float x )
{
  float P0[3];
  float P1[3];

  const signed long i0 = FASTFLOOR(x);
  const signed long i1 = i0 + 1;
  const float t = step( x - float(i0) );

  hash4d( P0, Pi[0], Pi[1], Pi[2], i0 );
  hash4d( P1, Pi[0], Pi[1], Pi[2], i1 );

  V[0] = mix( P0[0], P1[0], t );
  V[1] = mix( P0[1], P1[1], t );
  V[2] = mix( P0[2], P1[2], t );

  return;
}

/// returns V[3] in range +/- 15.5
inline void noise3dtX( float V[3], signed long Pi[3], float x, unsigned char uPlane )
{
  float P0[3];
  float P1[3];

  const signed long i0 = FASTFLOOR(x);
  const signed long i1 = i0 + 1;
  const float t = step( x - float(i0) );

  hash4dX( P0, Pi[0], Pi[1], Pi[2], i0, uPlane );
  hash4dX( P1, Pi[0], Pi[1], Pi[2], i1, uPlane );

  V[0] = mix( P0[0], P1[0], t );
  V[1] = mix( P0[1], P1[1], t );
  V[2] = mix( P0[2], P1[2], t );

  return;
}




void
simnoise3d( float V[3], const float P[3] ) {
float corner[7][3];
  float face[6];
  float Pt[3];
  float b[3];
  signed long Pi[3];
  int i;

  for(i=0; i<3; ++i) {
    Pi[i] = FASTFLOOR( P[i] );
    Pt[i] = P[i] - float( Pi[i] );
    b[i] = bell( Pt[i] );
  } // end for

  for( i=0; i<7; ++i ) {
    Pi[0] += i & 0x01;
    Pi[1] += (i>>1) & 0x01;
    Pi[2] += (i>>2) & 0x01;

    // this can be a hash, for a 3d input vector;
    // or a 1d noise for 4d position + time input vector
    hash3d( &corner[i][0], Pi[0], Pi[1], Pi[2] );

    Pi[0] -= i & 0x01;
    Pi[1] -= (i>>1) & 0x01;
    Pi[2] -= (i>>2) & 0x01;
  } // end for

  face[0] = ( corner[4][1] - corner[0][1] ) +
    ( corner[0][2] - corner[2][2] );
  face[1] = ( corner[5][1] - corner[1][1] ) +
    ( corner[1][2] - corner[3][2] );
  face[2] = ( corner[4][0] - corner[0][0] ) +
    ( corner[1][2] - corner[0][2] );
  face[3] = ( corner[6][0] - corner[2][0] ) +
    ( corner[3][2] - corner[2][2] );
  face[4] = ( corner[0][1] - corner[1][1] ) +
    ( corner[0][0] - corner[2][0] );
  face[5] = ( corner[4][1] - corner[5][1] ) +
    ( corner[4][0] - corner[6][0] );

  V[0] = (1.0F/32.0F) * b[1] * b[2] * mix( face[0], face[1], step(Pt[0]) );
  V[1] = (1.0F/32.0F) * b[0] * b[2] * mix( face[2], face[3], step(Pt[1]) );
  V[2] = (1.0F/32.0F) * b[0] * b[1] * mix( face[4], face[5], step(Pt[2]) );

  return;
}




/// returns a 3d vector, given a 4d position + time vector
void simnoise3dt( float V[3], const float P[4] ) {
  float corner[7][3];
  float face[6];
  float Pt[3];
  float b[3];
  signed long Pi[3];
  int i;

  for(i=0; i<3; ++i) {
    Pi[i] = FASTFLOOR( P[i] );
    Pt[i] = P[i] - float( Pi[i] );
    b[i] = bell( Pt[i] );
  } // end for

  for( i=0; i<7; ++i ) {
    Pi[0] += i & 0x01;
    Pi[1] += (i>>1) & 0x01;
    Pi[2] += (i>>2) & 0x01;

    // this can be a hash, for a 3d input vector;
    // or a 1d noise for 4d position + time input vector
    if( (Pi[0] ^ Pi[1] ^ Pi[2] ) & 0x1 )
      noise3dt( &corner[i][0], Pi, P[3] );
    else
      noise3dt( &corner[i][0], Pi, P[3] + 0.5F );

    Pi[0] -= i & 0x01;
    Pi[1] -= (i>>1) & 0x01;
    Pi[2] -= (i>>2) & 0x01;
  } // end for

  face[0] = ( corner[4][1] - corner[0][1] ) +
    ( corner[0][2] - corner[2][2] );
  face[1] = ( corner[5][1] - corner[1][1] ) +
    ( corner[1][2] - corner[3][2] );
  face[2] = ( corner[4][0] - corner[0][0] ) +
    ( corner[1][2] - corner[0][2] );
  face[3] = ( corner[6][0] - corner[2][0] ) +
    ( corner[3][2] - corner[2][2] );
  face[4] = ( corner[0][1] - corner[1][1] ) +
    ( corner[0][0] - corner[2][0] );
  face[5] = ( corner[4][1] - corner[5][1] ) +
    ( corner[4][0] - corner[6][0] );

  V[0] = (1.0F/32.0F) * b[1] * b[2] * mix( face[0], face[1], step(Pt[0]) );
  V[1] = (1.0F/32.0F) * b[0] * b[2] * mix( face[2], face[3], step(Pt[1]) );
  V[2] = (1.0F/32.0F) * b[0] * b[1] * mix( face[4], face[5], step(Pt[2]) );

  return;
}



/// returns a 3d vector, given a 4d position + time vector
/**
   given a "plane" it can return different values - this is handy, for example
   when combining into a fractal and you want to avoid the singularity that always
   occurs at the origin of the fractal space.
**/
void simnoise3dtX( float V[3], const float P[4], unsigned char uPlane ) {
  float corner[7][3];
  float face[6];
  float Pt[3];
  float b[3];
  signed long Pi[3];
  int i;

  for(i=0; i<3; ++i) {
    Pi[i] = FASTFLOOR( P[i] );
    Pt[i] = P[i] - float( Pi[i] );
    b[i] = bell( Pt[i] );
  } // end for

  for( i=0; i<7; ++i ) {
    Pi[0] += i & 0x01;
    Pi[1] += (i>>1) & 0x01;
    Pi[2] += (i>>2) & 0x01;

    // this can be a hash, for a 3d input vector;
    // or a 1d noise for 4d position + time input vector
    if( (Pi[0] ^ Pi[1] ^ Pi[2] ) & 0x1 )
      noise3dtX( &corner[i][0], Pi, P[3], uPlane );
    else
      noise3dtX( &corner[i][0], Pi, P[3] + 0.5F, uPlane );

    Pi[0] -= i & 0x01;
    Pi[1] -= (i>>1) & 0x01;
    Pi[2] -= (i>>2) & 0x01;
  } // end for

  face[0] = ( corner[4][1] - corner[0][1] ) +
    ( corner[0][2] - corner[2][2] );
  face[1] = ( corner[5][1] - corner[1][1] ) +
    ( corner[1][2] - corner[3][2] );
  face[2] = ( corner[4][0] - corner[0][0] ) +
    ( corner[1][2] - corner[0][2] );
  face[3] = ( corner[6][0] - corner[2][0] ) +
    ( corner[3][2] - corner[2][2] );
  face[4] = ( corner[0][1] - corner[1][1] ) +
    ( corner[0][0] - corner[2][0] );
  face[5] = ( corner[4][1] - corner[5][1] ) +
    ( corner[4][0] - corner[6][0] );

  V[0] = (1.0F/32.0F) * b[1] * b[2] * mix( face[0], face[1], step(Pt[0]) );
  V[1] = (1.0F/32.0F) * b[0] * b[2] * mix( face[2], face[3], step(Pt[1]) );
  V[2] = (1.0F/32.0F) * b[0] * b[1] * mix( face[4], face[5], step(Pt[2]) );

  return;
}

