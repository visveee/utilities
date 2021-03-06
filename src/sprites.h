#ifndef __SPRITES_H
#define __SPRITES_H

// not really a sprite, but a binary anyway:
const unsigned char Blank_g3p_phc[] = {
  0x50, 0x48, 0x53, 0x43, 0x4f, 0x4d, 0x50, 0x52, 0x00, 0x00, 0x01, 0x76,
  0x08, 0x07, 0xd5, 0x6b, 0x37, 0xba, 0xfc, 0x86, 0x23, 0x35, 0x8d, 0xc1,
  0x7f, 0xfd, 0xe0, 0x10, 0x54, 0x8f, 0xf7, 0xff, 0xff, 0xfe, 0xc4, 0xf4,
  0x43, 0x61, 0xa4, 0x50, 0xe8, 0x04, 0x02, 0x87, 0x50, 0x80, 0x40, 0x46,
  0x23, 0x60, 0x35, 0x60, 0x20, 0x30, 0x18, 0x2d, 0xf2, 0xe3, 0xe2, 0x54,
  0x2e, 0xa8, 0x10, 0x0b, 0x01, 0x00, 0xe0, 0x40, 0x22, 0x0a, 0x40, 0xda,
  0x69, 0xe4, 0x6f, 0x21, 0xf1, 0xbb, 0x7d, 0xff, 0xff, 0xff, 0xff, 0xa7,
  0xf5, 0x08, 0xd9, 0x71, 0x32, 0xf8, 0x7f, 0xd0, 0x28, 0x10, 0x03, 0xf8,
  0x00, 0x57, 0xee, 0x8f, 0xe7, 0xbe, 0x49, 0x7e, 0x15, 0xb0
};
const unsigned int Blank_g3p_phc_len = 106;

const color_t busymap_labels_palette[2] = {0x0000, 0x8410};

const unsigned char busymap_labels[7][21] = {
{ // SUN
  0x7a,0x28,0x80,
  0x82,0x2c,0x80,
  0x82,0x2c,0x80,
  0x72,0x2a,0x80,
  0x0a,0x29,0x80,
  0x0a,0x29,0x80,
  0xf1,0xc8,0x80
},
{ // MON
  0x89,0xC8,0xFF,
  0xDA,0x2C,0xFF,
  0xAA,0x2C,0xFF,
  0x8A,0x2A,0xFF,
  0x8A,0x29,0xFF,
  0x8A,0x29,0xFF,
  0x89,0xC8,0xFF
},
{ // TUE
  0xFA,0x2F,0xFF,
  0x22,0x28,0x7F,
  0x22,0x28,0x7F,
  0x22,0x2F,0x7F,
  0x22,0x28,0x7F,
  0x22,0x28,0x7F,
  0x21,0xCF,0xFF
},
{ // WED
  0xAB,0xEF,0x7F,
  0xAA,0x08,0xFF,
  0xAA,0x08,0xFF,
  0xAB,0xC8,0xFF,
  0xAA,0x08,0xFF,
  0xAA,0x08,0xFF,
  0x53,0xEF,0x7F
},
{ // THU
  0xFA,0x28,0xFF,
  0x22,0x28,0xFF,
  0x22,0x28,0xFF,
  0x23,0xE8,0xFF,
  0x22,0x28,0xFF,
  0x22,0x28,0xFF,
  0x22,0x27,0x7F
},
{ // FRI
  0xFB,0xC7,0x7F,
  0x82,0x22,0x7F,
  0x82,0x22,0x7F,
  0xF3,0xC2,0x7F,
  0x82,0x22,0x7F,
  0x82,0x22,0x7F,
  0x82,0x27,0x7F
},
{ // SAT
  0x79,0xcf,0x80,
  0x82,0x22,0x00,
  0x82,0x22,0x00,
  0x73,0xe2,0x00,
  0x0a,0x22,0x00,
  0x0a,0x22,0x00,
  0xf2,0x22,0x00
}
};

const color_t lock_icon_palette[2] = {0xffff, 0x0000};

const unsigned char lock_icon[24] = {
  0x1e,0x00,
  0x3f,0x00,
  0x73,0x80,
  0x61,0x80,
  0x61,0x80,
  0xff,0xc0,
  0xff,0xc0,
  0xff,0xc0,
  0xff,0xc0,
  0xff,0xc0,
  0xff,0xc0,
  0xff,0xc0
};

#endif