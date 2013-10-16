#ifndef __ALARM_H__
#define __ALARM_H__
const unsigned char code sounddata[]={
	0x7F, 0x80, 0x7F, 0x80, 0x7F, 0x80, 0x7F, 0x7E, 0x7F, 0x81, 0x7F, 0x80, 0x80, 0x7D, 0x7D,
	0x7F, 0x88, 0x7E, 0x6F, 0x80, 0x8C, 0x7A, 0x74, 0x85, 0x8C, 0x70, 0x7A, 0x94, 0x68, 0x73,
	0x9C, 0x77, 0x7A, 0x98, 0x7C, 0x75, 0x77, 0x87, 0x8B, 0x63, 0x7D, 0x91, 0x71, 0x7D, 0x84,
	0x70, 0x82, 0x82, 0x7D, 0x89, 0x77, 0x7B, 0x84, 0x7B, 0x82, 0x83, 0x78, 0x83, 0x88, 0x74,
	0x81, 0x86, 0x71, 0x80, 0x8B, 0x76, 0x82, 0x8C, 0x70, 0x7E, 0x8E, 0x6D, 0x7D, 0x97, 0x6F,
	0x74, 0x93, 0x76, 0x76, 0x99, 0x79, 0x75, 0x9C, 0x79, 0x5F, 0x97, 0x94, 0x63, 0x83, 0xA2,
	0x71, 0x6B, 0xA4, 0x7B, 0x63, 0xA7, 0x90, 0x4E, 0x84, 0xA9, 0x4E, 0x7E, 0xC6, 0x52, 0x3F,
	0xBA, 0xA1, 0x22, 0x98, 0xCF, 0x35, 0x64, 0xE2, 0x7B, 0x1E, 0xAE, 0xA2, 0x17, 0x6B, 0xC5,
	0x61, 0x37, 0xC4, 0xB8, 0x32, 0x78, 0xD6, 0x77, 0x34, 0xA0, 0xD6, 0x6A, 0x4E, 0xA8, 0xB2,
	0x5D, 0x5D, 0xA5, 0x8B, 0x6A, 0x74, 0x90, 0x8F, 0x6E, 0x7C, 0x86, 0x77, 0x87, 0x8D, 0x6C,
	0x6A, 0x9D, 0x8F, 0x56, 0x76, 0xA3, 0x92, 0x5D, 0x68, 0xA0, 0x9E, 0x6B, 0x5A, 0x8D, 0x9C,
	0x89, 0x6A, 0x71, 0x92, 0x93, 0x84, 0x78, 0x8B, 0x95, 0x6F, 0x56, 0x83, 0xB7, 0x89, 0x4F,
	0x8F, 0xB4, 0x59, 0x4A, 0x87, 0x8B, 0x88, 0x83, 0x8D, 0x8A, 0x73, 0x71, 0x6B, 0x71, 0x89,
	0x90, 0x98, 0x9E, 0x75, 0x56, 0x63, 0x6A, 0x73, 0x9C, 0xBE, 0x9F, 0x5D, 0x56, 0x7B, 0x69,
	0x60, 0xA1, 0xC9, 0xA0, 0x6E, 0x61, 0x71, 0x5E, 0x57, 0x9C, 0xC5, 0xB7, 0x7F, 0x57, 0x57,
	0x5A, 0x7B, 0x9B, 0x98, 0xA4, 0xA3, 0x67, 0x40, 0x4C, 0x7D, 0xA8, 0xAB, 0x9D, 0x91, 0x85,
	0x5A, 0x38, 0x62, 0xAD, 0xBB, 0xA3, 0x99, 0x7B, 0x52, 0x40, 0x66, 0x9D, 0xB0, 0xB0, 0x90,
	0x6B, 0x60, 0x47, 0x49, 0x91, 0xBE, 0xB9, 0x9B, 0x6A, 0x4D, 0x3F, 0x59, 0x96, 0xB8, 0xB3,
	0x90, 0x72, 0x64, 0x3F, 0x4D, 0x8E, 0xAF, 0xBD, 0xA0, 0x74, 0x5A, 0x3C, 0x56, 0x90, 0xAB,
	0xB3, 0xA0, 0x7A, 0x5B, 0x39, 0x4B, 0x97, 0xAA, 0xA8, 0x9B, 0x82, 0x69, 0x38, 0x57, 0x90,
	0xA5, 0xB6, 0x9E, 0x7F, 0x65, 0x39, 0x43, 0x8F, 0xB0, 0xAF, 0x9D, 0x82, 0x73, 0x3E, 0x40,
	0x8A, 0xAA, 0xB9, 0xA6, 0x84, 0x6F, 0x3B, 0x49, 0x8F, 0xA6, 0xA7, 0x9D, 0x8C, 0x6F, 0x3E,
	0x40, 0x83, 0xA8, 0xA8, 0xA7, 0x88, 0x74, 0x4D, 0x41, 0x7B, 0xA6, 0xB2, 0xA4, 0x88, 0x6F,
	0x48, 0x43, 0x76, 0xA0, 0xB0, 0xAF, 0x91, 0x69, 0x48, 0x47, 0x78, 0x9E, 0xAB, 0xAD, 0x92,
	0x6F, 0x4D, 0x42, 0x72, 0x9C, 0xAE, 0xB2, 0x8C, 0x6E, 0x52, 0x45, 0x76, 0x98, 0xA8, 0xAE,
	0x8C, 0x72, 0x56, 0x49, 0x71, 0x91, 0xAA, 0xB1, 0x8C, 0x6C, 0x52, 0x4C, 0x76, 0x91, 0xA5,
	0xAB, 0x8D, 0x74, 0x4D, 0x54, 0x7C, 0x8C, 0xA0, 0x9D, 0x8B, 0x6E, 0x4F, 0x64, 0x80, 0x8E,
	0x9E, 0x9B, 0x8A, 0x69, 0x57, 0x73, 0x7C, 0x85, 0x99, 0x94, 0x89, 0x66, 0x5E, 0x7B, 0x81,
	0x8B, 0x91, 0x92, 0x81, 0x65, 0x73, 0x7D, 0x80, 0x8A, 0x8A, 0x85, 0x77, 0x77, 0x80, 0x7E,
	0x83, 0x88, 0x81, 0x74, 0x75, 0x83, 0x83, 0x83, 0x8E, 0x85, 0x6A, 0x6B, 0x81, 0x89, 0x81,
	0x93, 0x97, 0x6D, 0x5B, 0x6F, 0x88, 0x86, 0x8F, 0xA2, 0x83, 0x5A, 0x5C, 0x7D, 0x80, 0x87,
	0xB0, 0x9A, 0x6A, 0x5F, 0x68, 0x74, 0x7E, 0xAB, 0xB1, 0x77, 0x6A, 0x6D, 0x60, 0x6B, 0x9A,
	0xB4, 0x8D, 0x71, 0x73, 0x61, 0x5A, 0x8A, 0xAD, 0x95, 0x7F, 0x7D, 0x68, 0x53, 0x86, 0xA9,
	0x89, 0x7E, 0x83, 0x77, 0x61, 0x7D, 0x9C, 0x87, 0x7D, 0x8A, 0x73, 0x5F, 0x87, 0xA1, 0x88,
	0x7C, 0x83, 0x67, 0x64, 0x95, 0x9E, 0x83, 0x7A, 0x7C, 0x62, 0x66, 0x9D, 0xA1, 0x81, 0x80,
	0x76, 0x5F, 0x70, 0x96, 0x9B, 0x89, 0x85, 0x61, 0x50, 0x86, 0xA5, 0x93, 0x8C, 0x86, 0x59,
	0x51, 0x8C, 0xA6, 0x8F, 0x86, 0x87, 0x6D, 0x5C, 0x7C, 0x92, 0x8C, 0x98, 0x8C, 0x5D, 0x51,
	0x7A, 0x97, 0x9E, 0xA2, 0x7D, 0x4F, 0x52, 0x84, 0xA5, 0xA2, 0x90, 0x74, 0x63, 0x67, 0x77,
	0x87, 0x9C, 0xA1, 0x87, 0x6B, 0x5E, 0x65, 0x7D, 0x9E, 0xAA, 0x8D, 0x6A, 0x58, 0x62, 0x85,
	0xA3, 0x9F, 0x84, 0x67, 0x63, 0x72, 0x89, 0x9A, 0x90, 0x78, 0x6B, 0x71, 0x7C, 0x87, 0x92,
	0x88, 0x7A, 0x74, 0x77, 0x77, 0x7F, 0x92, 0x94, 0x7C, 0x69, 0x70, 0x80, 0x8B, 0x8B, 0x86,
	0x84, 0x7D, 0x71, 0x6B, 0x7B, 0x91, 0x96, 0x8B, 0x79, 0x6C, 0x69, 0x7A, 0x93, 0x93, 0x86,
	0x7C, 0x6F, 0x6D, 0x7B, 0x8A, 0x8E, 0x87, 0x80, 0x7B, 0x71, 0x73, 0x83, 0x90, 0x8D, 0x80,
	0x75, 0x71, 0x7A, 0x8A, 0x8E, 0x80, 0x75, 0x74, 0x7C, 0x85, 0x89, 0x86, 0x7C, 0x77, 0x7A,
	0x7C, 0x85, 0x8B, 0x86, 0x7A, 0x74, 0x78, 0x7E, 0x88, 0x89, 0x80, 0x7B, 0x7B, 0x7C, 0x7B,
	0x80, 0x88, 0x87, 0x7F, 0x7C, 0x7A, 0x78, 0x80, 0x87, 0x87, 0x7F, 0x7B, 0x79, 0x7D, 0x85,
	0x86, 0x7F, 0x7C, 0x7F, 0x80, 0x7E, 0x80, 0x80, 0x82, 0x81, 0x7F, 0x7C, 0x7B, 0x81, 0x85,
	0x84, 0x80, 0x7B, 0x7B, 0x7E, 0x82, 0x83, 0x80, 0x80, 0x7F, 0x7D, 0x7D, 0x7F, 0x82, 0x83,
	0x81, 0x7F, 0x7D, 0x7C, 0x7F, 0x81, 0x82, 0x83, 0x7F, 0x7B, 0x7B, 0x81, 0x84, 0x80, 0x7E,
	0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x80, 0x80, 0x7F, 0x7E, 0x7D, 0x7F, 0x81, 0x81, 0x80, 0x7E,
	0x7C, 0x7D, 0x81, 0x81, 0x80, 0x7E, 0x7D, 0x7F, 0x81, 0x82, 0x7F, 0x7D, 0x7F, 0x7E, 0x80,
	0x80, 0x81, 0x81, 0x7F, 0x7E, 0x7E, 0x7F, 0x81, 0x82, 0x81, 0x7E, 0x7D, 0x7D, 0x7E, 0x80,
	0x82, 0x82, 0x7F, 0x7C, 0x7E, 0x7F, 0x80, 0x81, 0x81, 0x80, 0x7F, 0x7E, 0x7E, 0x80, 0x81,
	0x81, 0x80, 0x7E, 0x7E, 0x7F, 0x80, 0x81, 0x7F, 0x80, 0x7F, 0x80, 0x80, 0x7F, 0x80, 0x7E,
	0x80, 0x7E, 0x80, 0x7F, 0x80, 0x80, 0x80, 0x7F
};
#endif