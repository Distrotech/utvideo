/* �����R�[�h�͂r�i�h�r ���s�R�[�h�͂b�q�k�e */
/* $Id: PredictUnitTest.cpp 824 2011-12-11 13:55:21Z umezawa $ */

#include "stdafx.h"
#include "utvideo.h"
#include "Predict.h"

#ifdef _DEBUG

static const uint8_t PredictSrc[] = {
	0x87, 0x4d, 0x7c, 0x74, 0x9b, 0xa8, 0x5c, 0x4f, 0x70, 0x92, 0x8b, 0x6d, 0x76, 0x6d, 0x82, 0x86, 
	0x7d, 0x96, 0x6a, 0x92, 0x8a, 0x88, 0x68, 0x60, 0x87, 0xa5, 0x88, 0x8b, 0x76, 0x93, 0x82, 0x64, 
	0x89, 0x82, 0x87, 0x7c, 0x6e, 0x75, 0x65, 0x7f, 0x8c, 0x7e, 0x9a, 0x77, 0x52, 0x7c, 0x69, 0x6f, 
	0x70, 0x7f, 0x82, 0x74, 0x73, 0x7b, 0x72, 0x89, 0x70, 0x8c, 0xaa, 0x7f, 0xa5, 0x80, 0x9a, 0x6d, 
	0x58, 0x86, 0x7b, 0x84, 0x92, 0xad, 0x4e, 0x70, 0x5e, 0x5c, 0x70, 0x47, 0x8e, 0x89, 0x72, 0x66, 
	0x92, 0x8c, 0x95, 0x98, 0x4d, 0x4e, 0x6c, 0xa5, 0x90, 0x6f, 0x8f, 0x72, 0x80, 0x5b, 0x5d, 0x52, 
	0x82, 0x8e, 0x9a, 0x9d, 0xa1, 0x6b, 0xaf, 0x9c, 0x75, 0x4b, 0x74, 0x77, 0x86, 0xb3, 0x60, 0x73, 
	0x80, 0x76, 0xa2, 0x53, 0x61, 0x52, 0x88, 0x91, 0x6b, 0x96, 0xaf, 0x9e, 0x8a, 0x7e, 0x96, 0x88, 
	0xa9, 0x92, 0x82, 0x6f, 0x8d, 0x8d, 0x80, 0x9f, 0x8b, 0x9c, 0x83, 0xa3, 0x66, 0x78, 0x9c, 0x96, 
	0x6b, 0x8f, 0x85, 0x88, 0x97, 0x77, 0x81, 0x8c, 0x91, 0x96, 0x54, 0x4b, 0x79, 0x56, 0x8d, 0x78, 
	0x79, 0xa2, 0x9b, 0x89, 0x87, 0x94, 0x86, 0x86, 0x6b, 0x5a, 0x79, 0x7d, 0x88, 0x88, 0x6d, 0x7c, 
	0x7e, 0x65, 0x84, 0x90, 0x8f, 0xaf, 0x87, 0x67, 0x94, 0x98, 0x95, 0x92, 0x6c, 0x86, 0xb7, 0x86, 
	0x78, 0x7b, 0x8b, 0x7f, 0xae, 0x52, 0x4a, 0x65, 0x83, 0x5b, 0x79, 0x8a, 0x83, 0x8c, 0x80, 0x89, 
	0x76, 0x6c, 0x6e, 0x81, 0x8c, 0x78, 0x8f, 0x86, 0x7e, 0x9f, 0x6d, 0x78, 0x6c, 0x55, 0x91, 0x51, 
	0x8d, 0x6d, 0x5d, 0x6e, 0x80, 0x72, 0x81, 0xa9, 0x64, 0xa9, 0x7f, 0x93, 0x8a, 0x98, 0x79, 0x52, 
	0xa1, 0xab, 0x7f, 0x7d, 0x76, 0x67, 0x52, 0xa5, 0x62, 0x5e, 0x85, 0x9d, 0x9e, 0x90, 0x59, 0x4e, 
	0x68, 0x9b, 0x76, 0x4e, 0x82, 0x85, 0x72, 0xa0, 0x8f, 0x8d, 0x4f, 0x71, 0x92, 0x7b, 0x6d, 0x64, 
	0x5f, 0x68, 0x8a, 0x6f, 0x83, 0x94, 0xb6, 0x73, 0x7b, 0xab, 0x6b, 0x74, 0x9e, 0x81, 0x8e, 0x8e, 
	0x71, 0x96, 0x66, 0x82, 0x76, 0xa0, 0x75, 0x74, 0x5f, 0x6a, 0x6b, 0x7d, 0x8a, 0x44, 0x8d, 0x6b, 
	0x66, 0x8e, 0x9f, 0x7c, 0x51, 0x88, 0xa6, 0x7f, 0x94, 0x6e, 0x55, 0x99, 0x6a, 0xb6, 0xab, 0x8a, 
	0x81, 0x5d, 0x5e, 0x90, 0x4f, 0x55, 0x5a, 0x63, 0x50, 0x70, 0x8b, 0x91, 0x4a, 0x51, 0x9c, 0x68, 
	0x8c, 0x5f, 0x9b, 0x5b, 0x7a, 0xa0, 0xad, 0x51, 0x91, 0x9d, 0x94, 0x9e, 0x83, 0x61, 0x91, 0x68, 
	0x71, 0x69, 0x5e, 0x75, 0x73, 0x7d, 0xb6, 0x66, 0x66, 0xac, 0x74, 0xa6, 0x4a, 0x67, 0x76, 0x89, 
	0x7a, 0x7c, 0x50, 0xa8, 0x9c, 0xab, 0x6c, 0x5f, 0x66, 0x8f, 0x62, 0x9b, 0x41, 0x86, 0x74, 0x93, 
	0x75, 0x7c, 0x87, 0x7b, 0x67, 0x85, 0x8e, 0x6f, 0x88, 0x7a, 0x8f, 0x56, 0x99, 0x58, 0x72, 0x92, 
	0xa0, 0x57, 0x76, 0x86, 0x68, 0x89, 0x5a, 0x94, 0x80, 0x9b, 0x68, 0x87, 0x64, 0x6a, 0x85, 0x91, 
	0x8c, 0x88, 0x87, 0x8a, 0x56, 0x6e, 0x4a, 0x8d, 0x82, 0x6f, 0x6d, 0x56, 0xa5, 0x7f, 0x78, 0x97, 
	0x8a, 0x51, 0x8d, 0x6d, 0x73, 0x91, 0x90, 0x68, 0x65, 0x97, 0x77, 0x77, 0xa9, 0x6b, 0x8d, 0x97, 
	0x81, 0x6b, 0x96, 0x8d, 0x6e, 0x82, 0x62, 0x85, 0x8f, 0xa0, 0x90, 0x6e, 0xa0, 0x63, 0x8f, 0x7e, 
	0x4f, 0x50, 0x97, 0x53, 0x74, 0x83, 0x7e, 0x9d, 0x7a, 0xb4, 0xa1, 0x5e, 0x86, 0x7f, 0x46, 0x5c, 
	0x62, 0x60, 0x5e, 0xb6, 0x94, 0x90, 0x68, 0x8d, 0x94, 0x7b, 0x81, 0x95, 0x9c, 0x96, 0x65, 0xa3, 
	0x96, 0x80, 0x8f, 0x90, 0x9d, 0x86, 0x5f, 0x74, 0x9e, 0x7f, 0x8e, 0x6b, 0x88, 0x7b, 0x6d, 0x86, 
	0x97, 0x94, 0x81, 0x4e, 0x71, 0x73, 0x5c, 0xa0, 0x89, 0x45, 0x6e, 0x66, 0x59, 0x8c, 0x82, 0x66, 
	0x69, 0x89, 0x9c, 0x81, 0xba, 0x75, 0x68, 0x45, 0x67, 0x81, 0x57, 0x7b, 0xa1, 0x51, 0x7a, 0x78, 
	0x9a, 0xa2, 0x84, 0x48, 0x66, 0x88, 0xa2, 0x89, 0x59, 0xa1, 0x80, 0x6d, 0x7a, 0x80, 0xb5, 0x7c, 
	0x7b, 0xa1, 0x8a, 0x97, 0x9b, 0x7e, 0x99, 0xb0, 0x62, 0x86, 0x98, 0xaa, 0x8f, 0x83, 0x91, 0x78, 
	0x64, 0x80, 0x70, 0x55, 0x9f, 0x66, 0x60, 0x8c, 0x87, 0x5f, 0x81, 0x86, 0x72, 0x7c, 0x88, 0x72, 
	0x6f, 0x8b, 0x53, 0x8c, 0x96, 0x74, 0x7c, 0x60, 0x7f, 0xbd, 0x89, 0x7e, 0x8f, 0x9b, 0xb0, 0x97, 
	0x81, 0x71, 0x96, 0x83, 0x6f, 0x7b, 0x7e, 0x9e, 0x93, 0x74, 0x90, 0x8c, 0xa2, 0x91, 0x7d, 0x62, 
	0x8f, 0x67, 0x7e, 0x8b, 0x72, 0x52, 0x6f, 0x8a, 0x8e, 0x8a, 0x81, 0x4b, 0xaa, 0x96, 0x7d, 0x8c, 
	0x5f, 0x81, 0x70, 0x5b, 0xab, 0x94, 0x4c, 0x8f, 0x7c, 0x7a, 0x8b, 0x4c, 0x72, 0x9e, 0x6f, 0x4e, 
	0x90, 0x8c, 0x78, 0x87, 0xa2, 0xab, 0x87, 0x63, 0x8e, 0x66, 0x73, 0x72, 0x86, 0x7b, 0xa1, 0x8e, 
	0x78, 0x69, 0x66, 0x6b, 0x7a, 0x8a, 0x89, 0x91, 0xa4, 0x81, 0xb4, 0x76, 0xa6, 0x6f, 0x5d, 0x6e, 
	0x6d, 0x93, 0x8d, 0x7a, 0xa9, 0x8b, 0x9f, 0x97, 0x7c, 0x88, 0x73, 0x5e, 0x5d, 0x66, 0x64, 0x84, 
	0x86, 0x8a, 0x92, 0x83, 0x5a, 0x71, 0x73, 0x65, 0x99, 0x92, 0x77, 0x77, 0x67, 0x7c, 0x93, 0x89, 
	0x8f, 0x5d, 0x73, 0x79, 0x84, 0xa2, 0x4c, 0x74, 0x76, 0x8e, 0x9f, 0x53, 0x7a, 0x6d, 0x79, 0x61, 
	0x6e, 0x93, 0x73, 0x7e, 0x5c, 0x90, 0x7c, 0x82, 0x9a, 0x83, 0x78, 0x87, 0x7d, 0x91, 0xa1, 0x70, 
	0x8e, 0x85, 0xb2, 0x8b, 0x97, 0x7a, 0x5b, 0x97, 0x74, 0x8c, 0x74, 0x89, 0x8b, 0xa7, 0x8f, 0xab, 
	0x80, 0x76, 0x92, 0xa0, 0x87, 0x4b, 0x79, 0x99, 0x95, 0xa0, 0x88, 0x54, 0x64, 0xb0, 0xb2, 0x5c, 
	0x60, 0x8e, 0x67, 0x71, 0xa2, 0x73, 0xa4, 0x54, 0x9c, 0x5b, 0x86, 0x56, 0x79, 0x6a, 0x93, 0x7b, 
	0x74, 0x64, 0x74, 0x98, 0x9a, 0x74, 0x76, 0x70, 0x7a, 0x76, 0x82, 0xa7, 0x7c, 0x8e, 0x91, 0x81, 
	0xaf, 0x81, 0x55, 0x5c, 0x99, 0x82, 0x87, 0x6c, 0x46, 0xa3, 0x79, 0xa6, 0xa3, 0x68, 0x89, 0x6c, 
	0x64, 0x79, 0x87, 0x7c, 0x74, 0x6a, 0x99, 0x84, 0x9d, 0x77, 0x61, 0x7b, 0x9c, 0x59, 0x89, 0x9e, 
	0x65, 0x7d, 0x69, 0x95, 0x88, 0x9f, 0x8f, 0x8a, 0x9c, 0x7e, 0x8d, 0x74, 0x77, 0x81, 0x7e, 0x84, 
	0x93, 0x9e, 0x6a, 0x80, 0x9b, 0xaa, 0x6c, 0x81, 0x7e, 0x7a, 0x74, 0x8f, 0x92, 0x99, 0x65, 0x83, 
	0x6e, 0x79, 0x96, 0x6e, 0x63, 0x90, 0x58, 0x5b, 0x90, 0xad, 0x64, 0x90, 0x6f, 0x79, 0x5e, 0xa0, 
	0x8f, 0x62, 0x93, 0x88, 0x5d, 0x79, 0x7b, 0x73, 0x9c, 0x9a, 0x6f, 0x75, 0xa8, 0x92, 0xa6, 0x9d, 
	0x89, 0x99, 0x71, 0x5b, 0x67, 0xa7, 0x86, 0x68, 0xac, 0x5a, 0x8c, 0x86, 0x61, 0x6c, 0x90, 0x6e, 
	0x9e, 0xb0, 0x47, 0x83, 0x6f, 0x7a, 0x8a, 0x81, 0x64, 0x87, 0x9a, 0x84, 0x9a, 0x7e, 0x60, 0x69, 
	0x74, 0x9d, 0x91, 0xa0, 0x57, 0x8d, 0xb1, 0x6a, 0x74, 0x83, 0x52, 0x68, 0x82, 0x65, 0x97, 0x71, 
	0x8a, 0x8d, 0x87, 0x7e, 0x54, 0x8e, 0x69, 0xa4, 0x74, 0xac, 0x92, 0x7d, 0x5e, 0x74, 0x98, 0x96, 
	0x8e, 0x47, 0xbb, 0x6f, 0x59, 0x7b, 0x6b, 0x90, 0x97, 0x71, 0x62, 0x46, 0x72, 0x85, 0x8f, 0x8a, 
	0x7b, 0x65, 0x5e, 0x5a, 0x83, 0x81, 0x74, 0xad, 0x52, 0x6b, 0x61, 0x6d, 0x95, 0x97, 0x59, 0x81, 
	0x7f, 0xb1, 0x98, 0x7e, 0x7d, 0x76, 0x9b, 0x64, 0x81, 0x96, 0x80, 0x82, 0x76, 0x72, 0x9e, 0x74, 
};

static const size_t PredictLen_Left1 = 1024;

static const uint8_t PredictDst_Left1[] = {
	0x07, 0xc6, 0x2f, 0xf8, 0x27, 0x0d, 0xb4, 0xf3, 0x21, 0x22, 0xf9, 0xe2, 0x09, 0xf7, 0x15, 0x04, 
	0xf7, 0x19, 0xd4, 0x28, 0xf8, 0xfe, 0xe0, 0xf8, 0x27, 0x1e, 0xe3, 0x03, 0xeb, 0x1d, 0xef, 0xe2, 
	0x25, 0xf9, 0x05, 0xf5, 0xf2, 0x07, 0xf0, 0x1a, 0x0d, 0xf2, 0x1c, 0xdd, 0xdb, 0x2a, 0xed, 0x06, 
	0x01, 0x0f, 0x03, 0xf2, 0xff, 0x08, 0xf7, 0x17, 0xe7, 0x1c, 0x1e, 0xd5, 0x26, 0xdb, 0x1a, 0xd3, 
	0xeb, 0x2e, 0xf5, 0x09, 0x0e, 0x1b, 0xa1, 0x22, 0xee, 0xfe, 0x14, 0xd7, 0x47, 0xfb, 0xe9, 0xf4, 
	0x2c, 0xfa, 0x09, 0x03, 0xb5, 0x01, 0x1e, 0x39, 0xeb, 0xdf, 0x20, 0xe3, 0x0e, 0xdb, 0x02, 0xf5, 
	0x30, 0x0c, 0x0c, 0x03, 0x04, 0xca, 0x44, 0xed, 0xd9, 0xd6, 0x29, 0x03, 0x0f, 0x2d, 0xad, 0x13, 
	0x0d, 0xf6, 0x2c, 0xb1, 0x0e, 0xf1, 0x36, 0x09, 0xda, 0x2b, 0x19, 0xef, 0xec, 0xf4, 0x18, 0xf2, 
	0x21, 0xe9, 0xf0, 0xed, 0x1e, 0x00, 0xf3, 0x1f, 0xec, 0x11, 0xe7, 0x20, 0xc3, 0x12, 0x24, 0xfa, 
	0xd5, 0x24, 0xf6, 0x03, 0x0f, 0xe0, 0x0a, 0x0b, 0x05, 0x05, 0xbe, 0xf7, 0x2e, 0xdd, 0x37, 0xeb, 
	0x01, 0x29, 0xf9, 0xee, 0xfe, 0x0d, 0xf2, 0x00, 0xe5, 0xef, 0x1f, 0x04, 0x0b, 0x00, 0xe5, 0x0f, 
	0x02, 0xe7, 0x1f, 0x0c, 0xff, 0x20, 0xd8, 0xe0, 0x2d, 0x04, 0xfd, 0xfd, 0xda, 0x1a, 0x31, 0xcf, 
	0xf2, 0x03, 0x10, 0xf4, 0x2f, 0xa4, 0xf8, 0x1b, 0x1e, 0xd8, 0x1e, 0x11, 0xf9, 0x09, 0xf4, 0x09, 
	0xed, 0xf6, 0x02, 0x13, 0x0b, 0xec, 0x17, 0xf7, 0xf8, 0x21, 0xce, 0x0b, 0xf4, 0xe9, 0x3c, 0xc0, 
	0x3c, 0xe0, 0xf0, 0x11, 0x12, 0xf2, 0x0f, 0x28, 0xbb, 0x45, 0xd6, 0x14, 0xf7, 0x0e, 0xe1, 0xd9, 
	0x4f, 0x0a, 0xd4, 0xfe, 0xf9, 0xf1, 0xeb, 0x53, 0xbd, 0xfc, 0x27, 0x18, 0x01, 0xf2, 0xc9, 0xf5, 
	0x1a, 0x33, 0xdb, 0xd8, 0x34, 0x03, 0xed, 0x2e, 0xef, 0xfe, 0xc2, 0x22, 0x21, 0xe9, 0xf2, 0xf7, 
	0xfb, 0x09, 0x22, 0xe5, 0x14, 0x11, 0x22, 0xbd, 0x08, 0x30, 0xc0, 0x09, 0x2a, 0xe3, 0x0d, 0x00, 
	0xe3, 0x25, 0xd0, 0x1c, 0xf4, 0x2a, 0xd5, 0xff, 0xeb, 0x0b, 0x01, 0x12, 0x0d, 0xba, 0x49, 0xde, 
	0xfb, 0x28, 0x11, 0xdd, 0xd5, 0x37, 0x1e, 0xd9, 0x15, 0xda, 0xe7, 0x44, 0xd1, 0x4c, 0xf5, 0xdf, 
	0xf7, 0xdc, 0x01, 0x32, 0xbf, 0x06, 0x05, 0x09, 0xed, 0x20, 0x1b, 0x06, 0xb9, 0x07, 0x4b, 0xcc, 
	0x24, 0xd3, 0x3c, 0xc0, 0x1f, 0x26, 0x0d, 0xa4, 0x40, 0x0c, 0xf7, 0x0a, 0xe5, 0xde, 0x30, 0xd7, 
	0x09, 0xf8, 0xf5, 0x17, 0xfe, 0x0a, 0x39, 0xb0, 0x00, 0x46, 0xc8, 0x32, 0xa4, 0x1d, 0x0f, 0x13, 
	0xf1, 0x02, 0xd4, 0x58, 0xf4, 0x0f, 0xc1, 0xf3, 0x07, 0x29, 0xd3, 0x39, 0xa6, 0x45, 0xee, 0x1f, 
	0xe2, 0x07, 0x0b, 0xf4, 0xec, 0x1e, 0x09, 0xe1, 0x19, 0xf2, 0x15, 0xc7, 0x43, 0xbf, 0x1a, 0x20, 
	0x0e, 0xb7, 0x1f, 0x10, 0xe2, 0x21, 0xd1, 0x3a, 0xec, 0x1b, 0xcd, 0x1f, 0xdd, 0x06, 0x1b, 0x0c, 
	0xfb, 0xfc, 0xff, 0x03, 0xcc, 0x18, 0xdc, 0x43, 0xf5, 0xed, 0xfe, 0xe9, 0x4f, 0xda, 0xf9, 0x1f, 
	0xf3, 0xc7, 0x3c, 0xe0, 0x06, 0x1e, 0xff, 0xd8, 0xfd, 0x32, 0xe0, 0x00, 0x32, 0xc2, 0x22, 0x0a, 
	0xea, 0xea, 0x2b, 0xf7, 0xe1, 0x14, 0xe0, 0x23, 0x0a, 0x11, 0xf0, 0xde, 0x32, 0xc3, 0x2c, 0xef, 
	0xd1, 0x01, 0x47, 0xbc, 0x21, 0x0f, 0xfb, 0x1f, 0xdd, 0x3a, 0xed, 0xbd, 0x28, 0xf9, 0xc7, 0x16, 
	0x06, 0xfe, 0xfe, 0x58, 0xde, 0xfc, 0xd8, 0x25, 0x07, 0xe7, 0x06, 0x14, 0x07, 0xfa, 0xcf, 0x3e, 
	0xf3, 0xea, 0x0f, 0x01, 0x0d, 0xe9, 0xd9, 0x15, 0x2a, 0xe1, 0x0f, 0xdd, 0x1d, 0xf3, 0xf2, 0x19, 
	0x11, 0xfd, 0xed, 0xcd, 0x23, 0x02, 0xe9, 0x44, 0xe9, 0xbc, 0x29, 0xf8, 0xf3, 0x33, 0xf6, 0xe4, 
	0x03, 0x20, 0x13, 0xe5, 0x39, 0xbb, 0xf3, 0xdd, 0x22, 0x1a, 0xd6, 0x24, 0x26, 0xb0, 0x29, 0xfe, 
	0x22, 0x08, 0xe2, 0xc4, 0x1e, 0x22, 0x1a, 0xe7, 0xd0, 0x48, 0xdf, 0xed, 0x0d, 0x06, 0x35, 0xc7, 
	0xff, 0x26, 0xe9, 0x0d, 0x04, 0xe3, 0x1b, 0x17, 0xb2, 0x24, 0x12, 0x12, 0xe5, 0xf4, 0x0e, 0xe7, 
	0xec, 0x1c, 0xf0, 0xe5, 0x4a, 0xc7, 0xfa, 0x2c, 0xfb, 0xd8, 0x22, 0x05, 0xec, 0x0a, 0x0c, 0xea, 
	0xfd, 0x1c, 0xc8, 0x39, 0x0a, 0xde, 0x08, 0xe4, 0x1f, 0x3e, 0xcc, 0xf5, 0x11, 0x0c, 0x15, 0xe7, 
	0xea, 0xf0, 0x25, 0xed, 0xec, 0x0c, 0x03, 0x20, 0xf5, 0xe1, 0x1c, 0xfc, 0x16, 0xef, 0xec, 0xe5, 
	0x2d, 0xd8, 0x17, 0x0d, 0xe7, 0xe0, 0x1d, 0x1b, 0x04, 0xfc, 0xf7, 0xca, 0x5f, 0xec, 0xe7, 0x0f, 
	0xd3, 0x22, 0xef, 0xeb, 0x50, 0xe9, 0xb8, 0x43, 0xed, 0xfe, 0x11, 0xc1, 0x26, 0x2c, 0xd1, 0xdf, 
	0x42, 0xfc, 0xec, 0x0f, 0x1b, 0x09, 0xdc, 0xdc, 0x2b, 0xd8, 0x0d, 0xff, 0x14, 0xf5, 0x26, 0xed, 
	0xea, 0xf1, 0xfd, 0x05, 0x0f, 0x10, 0xff, 0x08, 0x13, 0xdd, 0x33, 0xc2, 0x30, 0xc9, 0xee, 0x11, 
	0xff, 0x26, 0xfa, 0xed, 0x2f, 0xe2, 0x14, 0xf8, 0xe5, 0x0c, 0xeb, 0xeb, 0xff, 0x09, 0xfe, 0x20, 
	0x02, 0x04, 0x08, 0xf1, 0xd7, 0x17, 0x02, 0xf2, 0x34, 0xf9, 0xe5, 0x00, 0xf0, 0x15, 0x17, 0xf6, 
	0x06, 0xce, 0x16, 0x06, 0x0b, 0x1e, 0xaa, 0x28, 0x02, 0x18, 0x11, 0xb4, 0x27, 0xf3, 0x0c, 0xe8, 
	0x0d, 0x25, 0xe0, 0x0b, 0xde, 0x34, 0xec, 0x06, 0x18, 0xe9, 0xf5, 0x0f, 0xf6, 0x14, 0x10, 0xcf, 
	0x1e, 0xf7, 0x2d, 0xd9, 0x0c, 0xe3, 0xe1, 0x3c, 0xdd, 0x18, 0xe8, 0x15, 0x02, 0x1c, 0xe8, 0x1c, 
	0xd5, 0xf6, 0x1c, 0x0e, 0xe7, 0xc4, 0x2e, 0x20, 0xfc, 0x0b, 0xe8, 0xcc, 0x10, 0x4c, 0x02, 0xaa, 
	0x04, 0x2e, 0xd9, 0x0a, 0x31, 0xd1, 0x31, 0xb0, 0x48, 0xbf, 0x2b, 0xd0, 0x23, 0xf1, 0x29, 0xe8, 
	0xf9, 0xf0, 0x10, 0x24, 0x02, 0xda, 0x02, 0xfa, 0x0a, 0xfc, 0x0c, 0x25, 0xd5, 0x12, 0x03, 0xf0, 
	0x2e, 0xd2, 0xd4, 0x07, 0x3d, 0xe9, 0x05, 0xe5, 0xda, 0x5d, 0xd6, 0x2d, 0xfd, 0xc5, 0x21, 0xe3, 
	0xf8, 0x15, 0x0e, 0xf5, 0xf8, 0xf6, 0x2f, 0xeb, 0x19, 0xda, 0xea, 0x1a, 0x21, 0xbd, 0x30, 0x15, 
	0xc7, 0x18, 0xec, 0x2c, 0xf3, 0x17, 0xf0, 0xfb, 0x12, 0xe2, 0x0f, 0xe7, 0x03, 0x0a, 0xfd, 0x06, 
	0x0f, 0x0b, 0xcc, 0x16, 0x1b, 0x0f, 0xc2, 0x15, 0xfd, 0xfc, 0xfa, 0x1b, 0x03, 0x07, 0xcc, 0x1e, 
	0xeb, 0x0b, 0x1d, 0xd8, 0xf5, 0x2d, 0xc8, 0x03, 0x35, 0x1d, 0xb7, 0x2c, 0xdf, 0x0a, 0xe5, 0x42, 
	0xef, 0xd3, 0x31, 0xf5, 0xd5, 0x1c, 0x02, 0xf8, 0x29, 0xfe, 0xd5, 0x06, 0x33, 0xea, 0x14, 0xf7, 
	0xec, 0x10, 0xd8, 0xea, 0x0c, 0x40, 0xdf, 0xe2, 0x44, 0xae, 0x32, 0xfa, 0xdb, 0x0b, 0x24, 0xde, 
	0x30, 0x12, 0x97, 0x3c, 0xec, 0x0b, 0x10, 0xf7, 0xe3, 0x23, 0x13, 0xea, 0x16, 0xe4, 0xe2, 0x09, 
	0x0b, 0x29, 0xf4, 0x0f, 0xb7, 0x36, 0x24, 0xb9, 0x0a, 0x0f, 0xcf, 0x16, 0x1a, 0xe3, 0x32, 0xda, 
	0x19, 0x03, 0xfa, 0xf7, 0xd6, 0x3a, 0xdb, 0x3b, 0xd0, 0x38, 0xe6, 0xeb, 0xe1, 0x16, 0x24, 0xfe, 
	0xf8, 0xb9, 0x74, 0xb4, 0xea, 0x22, 0xf0, 0x25, 0x07, 0xda, 0xf1, 0xe4, 0x2c, 0x13, 0x0a, 0xfb, 
	0xf1, 0xea, 0xf9, 0xfc, 0x29, 0xfe, 0xf3, 0x39, 0xa5, 0x19, 0xf6, 0x0c, 0x28, 0x02, 0xc2, 0x28, 
	0xfe, 0x32, 0xe7, 0xe6, 0xff, 0xf9, 0x25, 0xc9, 0x1d, 0x15, 0xea, 0x02, 0xf4, 0xfc, 0x2c, 0xd6, 
};

static const uint32_t PredictCount_Left1[] = {
	 7,  8, 15, 16,  8,  7, 13, 10,  6, 14, 14, 14, 14, 13,  8, 19, 
	 8, 11,  8,  7,  9, 11,  7,  8,  7,  7,  9, 10, 10,  7, 13, 10, 
	 9,  8, 12,  4,  9,  8,  7,  4,  7,  9,  4,  4,  9,  6,  6,  4, 
	 6,  4,  8,  4,  3,  2,  2,  2,  1,  6,  3,  1,  6,  1,  2,  0, 
	 2,  0,  2,  3,  4,  2,  1,  2,  2,  1,  1,  1,  2,  0,  0,  2, 
	 1,  0,  0,  1,  0,  0,  0,  0,  2,  0,  0,  0,  0,  1,  0,  1, 
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
	 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
	 0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0, 
	 0,  1,  0,  0,  3,  1,  1,  0,  0,  0,  2,  0,  0,  1,  1,  0, 
	 3,  1,  1,  0,  3,  1,  0,  3,  1,  3,  1,  2,  2,  4,  1,  3, 
	 3,  2,  5,  2,  2,  1,  1,  6,  3,  3,  2,  0,  6,  2,  2,  4, 
	 4,  5,  1,  5,  4,  8,  6,  3, 10,  6,  9,  6,  4,  9,  7,  6, 
	 9,  7,  9,  9,  4, 12,  2, 13,  5, 12, 13, 12, 15, 14,  4,  8, 
	11,  8, 12, 11, 11, 14,  9, 15, 12, 11,  9,  8, 11,  9, 16, 11, 
};

static const size_t PredictWidth_Median1  = 63;
static const size_t PredictHeight_Median1 = 16;

static const uint8_t PredictDst_Median1[] = {
	0x07, 0xc6, 0x2f, 0xf8, 0x27, 0x0d, 0xb4, 0xf3, 0x21, 0x22, 0xf9, 0xe2, 0x09, 0xf7, 0x15, 0x04, 
	0xf7, 0x19, 0xd4, 0x28, 0xf8, 0xfe, 0xe0, 0xf8, 0x27, 0x1e, 0xe3, 0x03, 0xeb, 0x1d, 0xef, 0xe2, 
	0x25, 0xf9, 0x05, 0xf5, 0xf2, 0x07, 0xf0, 0x1a, 0x0d, 0xf2, 0x1c, 0xdd, 0xdb, 0x2a, 0xed, 0x06, 
	0x01, 0x0f, 0x03, 0xf2, 0xff, 0x08, 0xf7, 0x17, 0xe7, 0x1c, 0x1e, 0xd5, 0x26, 0xdb, 0x1a, 0xe6, 
	0x0b, 0x0a, 0xfd, 0xe9, 0x01, 0x51, 0xae, 0x01, 0xcc, 0xfe, 0x14, 0xd1, 0x47, 0xfb, 0xe9, 0xf4, 
	0x13, 0x22, 0x03, 0x0b, 0xb7, 0x01, 0x1e, 0x1e, 0xeb, 0xe7, 0x1d, 0xf8, 0xf1, 0xdb, 0x02, 0xd0, 
	0x30, 0x07, 0x17, 0x11, 0x04, 0xda, 0x30, 0xed, 0xe7, 0xba, 0x29, 0x25, 0x0a, 0x40, 0xad, 0x12, 
	0x01, 0xf4, 0x2e, 0xb2, 0x06, 0xf1, 0x1f, 0x21, 0xda, 0x0d, 0x30, 0xef, 0x0a, 0xe4, 0x29, 0x07, 
	0x21, 0xf4, 0xf0, 0xdf, 0x03, 0x3f, 0xf3, 0x31, 0xee, 0x11, 0x10, 0x15, 0xc8, 0x12, 0x30, 0xfa, 
	0xdb, 0x1b, 0xf3, 0x3b, 0x0f, 0xe0, 0xdc, 0x0b, 0x22, 0x05, 0xdb, 0xe9, 0x2e, 0xdd, 0x3b, 0xeb, 
	0xf5, 0x1d, 0xf9, 0xea, 0x1c, 0xe5, 0xf2, 0x11, 0x0f, 0xe6, 0x1c, 0xf7, 0xde, 0x28, 0xe5, 0x02, 
	0x08, 0xc3, 0x31, 0x0c, 0x0e, 0x20, 0xd8, 0xfc, 0x02, 0xeb, 0xfd, 0x08, 0xe6, 0x02, 0x31, 0xcf, 
	0xf2, 0x03, 0x1c, 0xf2, 0x2f, 0xb1, 0xd9, 0x1b, 0x0d, 0xd8, 0xfe, 0x24, 0xf9, 0xf0, 0xf4, 0x1e, 
	0xe7, 0xf6, 0xff, 0x04, 0x15, 0xec, 0x0c, 0xf5, 0xf3, 0x4b, 0xd7, 0xff, 0x16, 0xc8, 0x3c, 0xc0, 
	0x13, 0xe0, 0xf0, 0x11, 0x05, 0xf2, 0x0f, 0x3e, 0xcc, 0x30, 0xd6, 0x0b, 0xf7, 0x29, 0xe1, 0xd7, 
	0x4f, 0x0a, 0xd4, 0xfe, 0xd9, 0xf1, 0xeb, 0x26, 0xbd, 0xfc, 0x27, 0x31, 0x01, 0xd9, 0xd3, 0xf5, 
	0x17, 0x23, 0xe7, 0xa9, 0x30, 0x0b, 0xed, 0x1d, 0x17, 0xfe, 0xc2, 0x22, 0x18, 0xf5, 0xe9, 0xf7, 
	0xfb, 0x07, 0x0f, 0xe3, 0x14, 0x05, 0x2b, 0xc5, 0xe7, 0x3e, 0xc0, 0x09, 0x41, 0xe3, 0x3d, 0x00, 
	0x03, 0x35, 0xd0, 0x0a, 0x02, 0x1f, 0xcc, 0x10, 0xb6, 0x0b, 0xed, 0x12, 0xff, 0xcb, 0x49, 0xca, 
	0xf1, 0x28, 0x13, 0xe4, 0xe4, 0x37, 0x01, 0x1c, 0x19, 0xda, 0xcf, 0x43, 0xda, 0x5d, 0x00, 0xdf, 
	0xe6, 0xe7, 0x10, 0x0e, 0xbf, 0x06, 0xd7, 0x09, 0xed, 0x21, 0x1a, 0xff, 0xcf, 0x07, 0x4b, 0xd1, 
	0x24, 0xd3, 0x3c, 0xc0, 0x0e, 0x04, 0x3a, 0xa4, 0x10, 0x32, 0xf7, 0x00, 0x02, 0xd3, 0x30, 0xf4, 
	0xe4, 0x03, 0xdc, 0x17, 0xd4, 0x0a, 0x3a, 0xc5, 0xfc, 0x45, 0xc8, 0x25, 0xea, 0xda, 0x0f, 0x18, 
	0xec, 0xf1, 0xd4, 0x58, 0xf4, 0x05, 0xe8, 0xde, 0x07, 0x3a, 0xc9, 0x39, 0x8b, 0x45, 0xee, 0x1f, 
	0x06, 0x07, 0xf7, 0x2c, 0xec, 0x1e, 0x09, 0xf4, 0x18, 0xef, 0x0f, 0x0c, 0x43, 0xbc, 0x1a, 0x06, 
	0x3b, 0xb7, 0x1f, 0x0c, 0xc8, 0x14, 0x09, 0x03, 0xe3, 0x1b, 0xca, 0x1f, 0xff, 0xd9, 0x1d, 0x0c, 
	0x03, 0x07, 0xff, 0x05, 0xcc, 0xdf, 0xe4, 0x43, 0xd6, 0xfb, 0xcc, 0x0c, 0x3e, 0xda, 0xef, 0x1f, 
	0xf3, 0xf3, 0xe5, 0xe0, 0xf7, 0x25, 0x0c, 0xd8, 0xd6, 0x35, 0xdc, 0x36, 0x23, 0xd4, 0x03, 0x22, 
	0xea, 0xe4, 0x2b, 0x0b, 0xe1, 0x0b, 0xf3, 0x0a, 0x15, 0x11, 0x29, 0xd5, 0x48, 0xc3, 0x0c, 0xe1, 
	0xf8, 0xe2, 0x37, 0xda, 0x00, 0x29, 0xea, 0x1f, 0xdd, 0x4c, 0xed, 0xe0, 0x22, 0xf9, 0xbb, 0x16, 
	0x06, 0xfe, 0xfb, 0x60, 0xde, 0x20, 0xd8, 0x25, 0x1a, 0xe9, 0x1d, 0xf0, 0x1d, 0x01, 0xce, 0x3e, 
	0x2c, 0xea, 0x22, 0x01, 0x0c, 0xea, 0xf7, 0x15, 0x07, 0x01, 0x0f, 0xc2, 0x1d, 0xee, 0xe8, 0x19, 
	0x27, 0xfd, 0xf4, 0xe0, 0x0f, 0x11, 0xd7, 0x3a, 0xe9, 0xbc, 0x29, 0xc6, 0xf6, 0x07, 0x04, 0x13, 
	0x03, 0xf2, 0x49, 0xe5, 0x37, 0xc0, 0xd4, 0xdd, 0xe8, 0x1a, 0xf9, 0xfc, 0x26, 0xe9, 0x1e, 0xfe, 
	0x24, 0x0a, 0xce, 0xc4, 0x1e, 0x22, 0x15, 0xe7, 0xde, 0x42, 0xdf, 0xe6, 0x0d, 0x1b, 0x12, 0xd4, 
	0xff, 0x17, 0xe9, 0x00, 0x15, 0x0a, 0x1b, 0x12, 0xd1, 0x15, 0x2d, 0x12, 0xf2, 0x02, 0x0b, 0xe1, 
	0xec, 0x1c, 0x22, 0xe4, 0x48, 0xde, 0xc0, 0x2c, 0x3f, 0xd8, 0x22, 0x12, 0xe6, 0x0a, 0x22, 0xea, 
	0xe6, 0x09, 0xd2, 0x00, 0x21, 0xeb, 0x2b, 0xe4, 0x05, 0x66, 0xcc, 0xdd, 0x3e, 0x0c, 0x17, 0xe7, 
	0xe2, 0xf0, 0x4e, 0xed, 0xe7, 0xf2, 0x03, 0x45, 0xf2, 0xf4, 0x23, 0xfc, 0x16, 0xdc, 0x01, 0xe6, 
	0x07, 0xdd, 0x0a, 0x09, 0xf4, 0xc5, 0x06, 0x28, 0x04, 0xf2, 0xe5, 0xca, 0x5f, 0xec, 0x00, 0x23, 
	0xd3, 0x22, 0x0a, 0xbc, 0x50, 0xef, 0xb8, 0x43, 0x15, 0xf9, 0x0c, 0xd5, 0x1c, 0x20, 0xe7, 0xdf, 
	0x26, 0x34, 0xec, 0x05, 0x2e, 0x09, 0xf8, 0xdc, 0xed, 0xdd, 0x0d, 0xee, 0x08, 0xe0, 0x26, 0x03, 
	0xfa, 0xd3, 0xfd, 0x05, 0x03, 0x0d, 0xeb, 0x08, 0x30, 0xdd, 0x33, 0xc2, 0x30, 0xdd, 0xfb, 0xe4, 
	0x06, 0x15, 0xfa, 0x06, 0x4f, 0xe2, 0x14, 0xf8, 0xe9, 0x0c, 0x21, 0xb4, 0xff, 0x09, 0xef, 0x25, 
	0x02, 0x15, 0x1d, 0xd8, 0xd7, 0x25, 0xe4, 0xf2, 0x34, 0xf9, 0x24, 0x00, 0xc9, 0x15, 0x38, 0xf6, 
	0x06, 0xe2, 0x07, 0xeb, 0x02, 0x1e, 0xce, 0xfd, 0x10, 0x18, 0x12, 0xb4, 0x27, 0xcd, 0x0c, 0xe9, 
	0x0d, 0x28, 0xe0, 0x04, 0xd2, 0x34, 0xeb, 0xf3, 0x19, 0xcf, 0x02, 0xe1, 0x0e, 0x26, 0x10, 0xd0, 
	0xfb, 0xf8, 0x38, 0xd9, 0x0c, 0xdb, 0xe1, 0x3c, 0xdd, 0x19, 0xfd, 0x16, 0x02, 0x1e, 0xe8, 0x1c, 
	0xd5, 0xee, 0x1c, 0x37, 0xe7, 0xc4, 0x2e, 0x00, 0x03, 0x26, 0xe8, 0xdc, 0xfb, 0x35, 0x0c, 0xaa, 
	0x04, 0x1b, 0xd9, 0xff, 0x13, 0x27, 0x30, 0xb0, 0x30, 0xbc, 0x33, 0xd0, 0x23, 0xf1, 0x32, 0xe8, 
	0xe1, 0xf1, 0x05, 0x3c, 0x02, 0xee, 0xfc, 0xe2, 0x0a, 0xfe, 0xfd, 0x2a, 0xd5, 0x02, 0x21, 0xf0, 
	0x2e, 0xcf, 0xd4, 0xfb, 0x3d, 0x08, 0xf0, 0xf8, 0xc2, 0x5d, 0xd6, 0x2b, 0xfc, 0xd9, 0x05, 0xec, 
	0xf8, 0xf9, 0x00, 0xf5, 0x29, 0xf1, 0x0f, 0xef, 0x0e, 0xef, 0x0d, 0x17, 0xec, 0xbb, 0x30, 0x15, 
	0xc7, 0x18, 0xec, 0xfb, 0x15, 0xfb, 0x3b, 0xee, 0x41, 0xe2, 0x37, 0xe7, 0x0d, 0xee, 0x03, 0x0d, 
	0x1f, 0x0b, 0xcc, 0x14, 0x27, 0x0f, 0xc8, 0x0b, 0x01, 0xf8, 0xd5, 0x1b, 0x03, 0x07, 0xdc, 0xf0, 
	0xed, 0x24, 0x1d, 0xd5, 0xf5, 0x28, 0xe3, 0x15, 0xed, 0x34, 0xb7, 0x2c, 0x07, 0xf0, 0xf2, 0x42, 
	0xef, 0xd3, 0x31, 0xfd, 0xdf, 0xed, 0x02, 0xdf, 0x29, 0x14, 0xd5, 0xe5, 0x4f, 0xea, 0x08, 0x30, 
	0xec, 0x24, 0xd8, 0xea, 0xf5, 0x40, 0xe4, 0xd0, 0x44, 0xae, 0x32, 0xfa, 0xdb, 0x0b, 0x1e, 0xdb, 
	0x25, 0x46, 0x97, 0x21, 0xdd, 0x0e, 0x09, 0xfa, 0xe7, 0x23, 0x0b, 0xea, 0x0f, 0x18, 0xdd, 0x09, 
	0x00, 0x0c, 0x1c, 0x1a, 0xb7, 0x36, 0x24, 0xb9, 0xed, 0x1f, 0xc2, 0x16, 0x10, 0xfe, 0xf7, 0xe2, 
	0x28, 0xfa, 0xff, 0x21, 0xd6, 0x38, 0xe3, 0x12, 0xd2, 0x3d, 0xe6, 0xd5, 0xe1, 0x02, 0x24, 0x0d, 
	0xf5, 0xd6, 0x74, 0xb4, 0xb2, 0x22, 0x03, 0xe4, 0x3d, 0xda, 0xf1, 0xe5, 0x21, 0xf5, 0x21, 0xec, 
	0xdf, 0x1e, 0xdb, 0xfc, 0x1e, 0xf7, 0xf3, 0x49, 0xa5, 0x06, 0xf6, 0xf6, 0x28, 0x20, 0xc2, 0x1d, 
};

static const uint32_t PredictCount_Median1[] = {
	11, 12, 15, 18,  8, 11, 11, 15,  7, 11, 13, 13, 16, 12,  6, 12, 
	 7,  6,  9,  5,  6, 15,  5,  8,  6,  5,  7,  7, 11, 11, 13,  9, 
	 4, 11, 13,  6,  8,  8,  7,  7,  8,  8,  2,  4,  4,  1,  5,  2, 
	13,  5,  3,  2,  4,  3,  2,  5,  3,  1,  4,  4,  4,  4,  5,  2, 
	 2,  2,  2,  4,  1,  3,  1,  1,  2,  3,  0,  2,  1,  0,  1,  3, 
	 1,  1,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  2,  0,  1, 
	 1,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
	 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0, 
	 0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0, 
	 0,  0,  0,  0,  1,  1,  0,  0,  0,  1,  1,  0,  0,  1,  2,  0, 
	 1,  1,  2,  0,  4,  0,  1,  4,  1,  1,  1,  2,  4,  1,  0,  1, 
	 5,  0,  6,  2,  2,  3,  2,  1,  5,  2,  3,  1,  7,  1,  3,  5, 
	 5,  3,  3,  6,  8,  9,  6,  5,  7,  7,  8,  9,  7, 12,  5,  8, 
	 8,  8,  9,  6, 12,  7,  9, 14,  6, 10, 10,  9, 11, 12,  8,  9, 
	10,  9, 14,  9, 10, 10,  5, 12, 11,  9,  6, 10,  8,  8,  9, 11, 
};

static const size_t PredictWidth_Median16  = 64;
static const size_t PredictHeight_Median16 = 16;

static const uint8_t PredictDst_Median16[] = {
	0x07, 0xc6, 0x2f, 0xf8, 0x27, 0x0d, 0xb4, 0xf3, 0x21, 0x22, 0xf9, 0xe2, 0x09, 0xf7, 0x15, 0x04, 
	0xf7, 0x19, 0xd4, 0x28, 0xf8, 0xfe, 0xe0, 0xf8, 0x27, 0x1e, 0xe3, 0x03, 0xeb, 0x1d, 0xef, 0xe2, 
	0x25, 0xf9, 0x05, 0xf5, 0xf2, 0x07, 0xf0, 0x1a, 0x0d, 0xf2, 0x1c, 0xdd, 0xdb, 0x2a, 0xed, 0x06, 
	0x01, 0x0f, 0x03, 0xf2, 0xff, 0x08, 0xf7, 0x17, 0xe7, 0x1c, 0x1e, 0xd5, 0x26, 0xdb, 0x1a, 0xd3, 
	0xd1, 0x39, 0xf5, 0x10, 0xf7, 0x0e, 0xed, 0x22, 0xee, 0xdc, 0x14, 0xda, 0x3e, 0x04, 0xe9, 0xf0, 
	0x2c, 0xf6, 0x2b, 0x03, 0xbd, 0x01, 0x1e, 0x41, 0xeb, 0xca, 0x20, 0xe3, 0x0e, 0xc8, 0x02, 0xf5, 
	0x0b, 0x0c, 0x0c, 0x0e, 0x12, 0xca, 0x4a, 0xed, 0xd9, 0xd6, 0x0d, 0x03, 0x34, 0x2d, 0xc0, 0x0d, 
	0x0d, 0xf6, 0x29, 0xbf, 0x0e, 0xe9, 0x36, 0x08, 0xf3, 0x0f, 0x05, 0x1a, 0xe5, 0xfe, 0xfe, 0x1b, 
	0x36, 0xe9, 0xfb, 0xeb, 0x10, 0xe5, 0x32, 0x1f, 0xfe, 0x13, 0xe7, 0x49, 0xc3, 0x12, 0x2a, 0x06, 
	0xd5, 0x24, 0xf0, 0x00, 0x4a, 0xe0, 0x0a, 0xe7, 0x05, 0x26, 0xbe, 0xf7, 0x20, 0xfb, 0x35, 0xf6, 
	0xf7, 0x1d, 0xf9, 0xec, 0xfa, 0x29, 0xd7, 0x00, 0xf6, 0x0f, 0x05, 0x04, 0x02, 0xd5, 0x0d, 0x09, 
	0xfe, 0xef, 0xf3, 0x3d, 0xff, 0x2f, 0xd8, 0xd7, 0x2d, 0x02, 0xe6, 0xfd, 0xe2, 0x1a, 0x21, 0xdd, 
	0xd1, 0x03, 0x10, 0x07, 0x21, 0xa4, 0xf8, 0xfc, 0x1e, 0xc7, 0x1e, 0xf1, 0x1d, 0x09, 0xe4, 0x09, 
	0x0b, 0xdd, 0x02, 0x10, 0xfc, 0x01, 0x0e, 0xf7, 0xf3, 0x1c, 0x10, 0x14, 0xf3, 0xff, 0x05, 0xd5, 
	0x3b, 0xcb, 0xf0, 0x11, 0x12, 0xe5, 0x0f, 0x28, 0xd6, 0x4f, 0xd6, 0x14, 0xf7, 0x0e, 0xfc, 0xd6, 
	0x4d, 0x23, 0xd4, 0xf2, 0xf9, 0xd1, 0xeb, 0x53, 0xbd, 0xf8, 0x27, 0x18, 0x27, 0xf2, 0xa2, 0xf5, 
	0x1a, 0x30, 0xdb, 0xd8, 0x05, 0x33, 0xf5, 0x2e, 0xef, 0x26, 0xc2, 0x11, 0x21, 0xe9, 0xf2, 0xee, 
	0xfb, 0x09, 0x20, 0xe5, 0x09, 0x1c, 0x22, 0xc6, 0x08, 0x0f, 0xf2, 0xfe, 0x32, 0xfa, 0xfd, 0x3d, 
	0xe3, 0x29, 0xe0, 0x14, 0xf4, 0x2e, 0xd5, 0xd7, 0xfb, 0xc6, 0x01, 0xfe, 0x0d, 0xac, 0x49, 0x05, 
	0xc5, 0x1e, 0x20, 0xdf, 0xdb, 0x37, 0x33, 0xd9, 0x32, 0xde, 0xd0, 0x2c, 0xd0, 0x4c, 0x2c, 0xea, 
	0xf7, 0xc2, 0x01, 0x42, 0xbf, 0x03, 0x05, 0xdb, 0xed, 0x20, 0x3c, 0x06, 0xb8, 0x07, 0x4b, 0xd5, 
	0x29, 0xd3, 0x1a, 0xdb, 0x0b, 0x15, 0xf7, 0xde, 0x38, 0xf2, 0x29, 0x0a, 0xe5, 0xe0, 0x23, 0xd7, 
	0x09, 0xd3, 0xf8, 0xfb, 0xfe, 0xe0, 0x41, 0xb1, 0x07, 0x42, 0xc8, 0x29, 0xa4, 0x23, 0xe9, 0x1e, 
	0xf6, 0xee, 0xc3, 0x58, 0x1f, 0x0f, 0xc1, 0xf3, 0xf2, 0x29, 0xec, 0x02, 0xd5, 0xf9, 0xee, 0x1f, 
	0xeb, 0x1f, 0x0b, 0xeb, 0x18, 0x1e, 0x09, 0xe1, 0x2c, 0xf2, 0x04, 0xc5, 0x4f, 0xbf, 0xd6, 0x2a, 
	0x0e, 0xe4, 0xe3, 0x2b, 0xe2, 0xfb, 0xc4, 0x3a, 0xec, 0x0f, 0xd4, 0x15, 0xe1, 0x09, 0xf4, 0x29, 
	0xfb, 0x04, 0x0a, 0x03, 0xce, 0x0e, 0xa3, 0x27, 0xf5, 0xc3, 0xfe, 0xb7, 0x4f, 0xda, 0xf9, 0x0e, 
	0x02, 0xc7, 0x3d, 0xc5, 0x06, 0x0f, 0x24, 0xe5, 0xfd, 0x09, 0x0d, 0xdc, 0x68, 0xc2, 0x22, 0x04, 
	0x08, 0xea, 0x20, 0x03, 0xf5, 0xfd, 0xd7, 0x23, 0x07, 0x1f, 0xf0, 0x17, 0x07, 0x04, 0x1d, 0xec, 
	0xc3, 0x01, 0x28, 0xbc, 0x21, 0xfa, 0x24, 0x09, 0xf1, 0x1f, 0x20, 0xbd, 0x28, 0xf9, 0xc1, 0x0a, 
	0x06, 0xfe, 0xfe, 0x55, 0x12, 0xfc, 0xfc, 0x00, 0x12, 0xfa, 0x08, 0x2b, 0xf7, 0x17, 0xd6, 0x1f, 
	0x00, 0x23, 0x02, 0x21, 0x0d, 0xe9, 0xd9, 0x15, 0x2d, 0xe1, 0x17, 0xdd, 0xeb, 0x10, 0xe0, 0x0f, 
	0x16, 0x13, 0xeb, 0xcd, 0x23, 0xf1, 0xfa, 0x21, 0xe9, 0xab, 0x29, 0xf8, 0xc1, 0x33, 0xf3, 0xe8, 
	0x1a, 0x20, 0x05, 0x29, 0x39, 0xbb, 0xf3, 0xbe, 0x22, 0xe0, 0xd6, 0x24, 0x1b, 0xb7, 0x34, 0xfe, 
	0x22, 0x0a, 0xe4, 0x92, 0x1e, 0x22, 0x3a, 0xe7, 0xc9, 0x48, 0xdf, 0xd9, 0x06, 0x06, 0x50, 0xc7, 
	0xff, 0x26, 0xe9, 0x0c, 0xfe, 0xf8, 0x3a, 0x17, 0xb2, 0x24, 0x0a, 0x35, 0xe5, 0x01, 0x1c, 0xe7, 
	0xdb, 0x1c, 0xf0, 0x07, 0x2e, 0xc7, 0x04, 0xec, 0xfe, 0x1a, 0x13, 0x0d, 0xf9, 0xf0, 0x0c, 0x06, 
	0xfd, 0x02, 0xb7, 0x39, 0xdc, 0xff, 0x14, 0x07, 0x18, 0x3c, 0xf6, 0xf5, 0xee, 0x4a, 0x15, 0xe9, 
	0xe7, 0xe8, 0x25, 0x29, 0xec, 0xf3, 0xe9, 0x20, 0x25, 0xd3, 0x1c, 0x0f, 0x16, 0xef, 0xc8, 0xe6, 
	0x2d, 0xc6, 0x17, 0x00, 0xe3, 0xe0, 0x02, 0x04, 0x2c, 0xfc, 0xe9, 0xb8, 0x5f, 0xf8, 0xe7, 0x14, 
	0xe7, 0x06, 0xff, 0x06, 0x0c, 0x22, 0xbe, 0x17, 0xf2, 0x1b, 0x0a, 0xc1, 0x26, 0x22, 0xd1, 0xdf, 
	0x42, 0xfc, 0x24, 0xfb, 0x11, 0x2b, 0xdc, 0xf8, 0x0f, 0xa9, 0x0d, 0xff, 0x03, 0xe9, 0x11, 0xf7, 
	0xf7, 0xf8, 0xd8, 0x05, 0x0f, 0x0f, 0xff, 0xf3, 0x13, 0xfc, 0x24, 0xc6, 0x1a, 0xda, 0xee, 0x11, 
	0xde, 0x2c, 0xfa, 0xed, 0x37, 0x02, 0x14, 0xf8, 0xe5, 0x0c, 0xf2, 0x13, 0xb3, 0x09, 0xfe, 0x11, 
	0x27, 0x04, 0x19, 0x06, 0xaf, 0x17, 0x27, 0xd6, 0x34, 0xfb, 0xe5, 0x2b, 0xf0, 0xe9, 0x24, 0x17, 
	0xff, 0xd1, 0x16, 0xf7, 0xf0, 0x15, 0xc5, 0x28, 0xe8, 0x28, 0x11, 0xb5, 0x13, 0xf3, 0xe6, 0xe8, 
	0x0d, 0x2a, 0xe3, 0x0b, 0xde, 0x24, 0xed, 0xfe, 0x05, 0x02, 0xc4, 0x11, 0xd7, 0x22, 0x22, 0xcf, 
	0x1f, 0xf2, 0x2d, 0xec, 0xee, 0xef, 0xcd, 0x3c, 0xf8, 0x0c, 0xfd, 0x2a, 0x03, 0x1c, 0xea, 0x1c, 
	0xd5, 0xf2, 0x14, 0x1d, 0x10, 0xc4, 0x2c, 0x2e, 0xfc, 0x0e, 0x03, 0xcc, 0x10, 0x37, 0x02, 0xb4, 
	0xfe, 0x31, 0xd9, 0x04, 0x26, 0xd1, 0x58, 0xb0, 0x46, 0xbf, 0x1a, 0x03, 0xff, 0xfd, 0x1d, 0x00, 
	0xf9, 0xd1, 0x10, 0x1a, 0x24, 0xda, 0x02, 0xf4, 0xf2, 0xfc, 0x0c, 0x20, 0xdf, 0xfe, 0xf3, 0x11, 
	0x21, 0xdb, 0xa7, 0x07, 0x31, 0x06, 0x24, 0xd5, 0xda, 0x45, 0xee, 0x1d, 0xfd, 0xc1, 0x21, 0xc7, 
	0xf8, 0x15, 0xf5, 0xe7, 0xf8, 0x1f, 0x20, 0xeb, 0x19, 0xd7, 0xea, 0x27, 0x21, 0xa9, 0x2e, 0x42, 
	0xc7, 0xef, 0x02, 0x24, 0xe6, 0x2c, 0xeb, 0x36, 0x00, 0x23, 0x07, 0x17, 0xfe, 0x17, 0xeb, 0x09, 
	0x16, 0x1b, 0xcc, 0xf2, 0x19, 0x35, 0xc2, 0x15, 0xfd, 0x00, 0xf2, 0xf6, 0x16, 0x07, 0xcc, 0x1e, 
	0xbf, 0x0b, 0x41, 0xd8, 0xca, 0x2d, 0xc8, 0x03, 0x4a, 0x0a, 0xe1, 0xff, 0xdf, 0x11, 0xd5, 0x42, 
	0xf7, 0xd3, 0x23, 0x00, 0xdd, 0x1c, 0xe2, 0xf8, 0x10, 0x23, 0xeb, 0xfa, 0x12, 0x2d, 0x14, 0xf7, 
	0x24, 0x10, 0xec, 0xc6, 0x0c, 0x29, 0xef, 0xe2, 0x32, 0xcc, 0x23, 0x12, 0xdb, 0x01, 0x24, 0xde, 
	0x21, 0x12, 0xcb, 0x26, 0xd4, 0xfc, 0x1e, 0xf7, 0xe6, 0x23, 0x19, 0xea, 0x13, 0xe4, 0xfb, 0xeb, 
	0x0b, 0x24, 0xf4, 0x32, 0xc2, 0x09, 0x59, 0xb9, 0xe4, 0xf2, 0xee, 0xea, 0x1a, 0xe3, 0x39, 0xd1, 
	0x19, 0x2b, 0xf4, 0xf7, 0xf7, 0x1e, 0xdb, 0x3b, 0xd0, 0x38, 0x11, 0xeb, 0xb6, 0x16, 0x10, 0xfe, 
	0x05, 0xae, 0x74, 0xca, 0xea, 0xe2, 0xf0, 0x28, 0xeb, 0x17, 0xd6, 0xe4, 0x2c, 0x13, 0xff, 0x1c, 
	0xdd, 0xd8, 0xf9, 0xd7, 0x29, 0xfe, 0xea, 0x39, 0xc2, 0xf6, 0xe3, 0x0c, 0x12, 0x19, 0xe0, 0x1f, 
	0xfe, 0x14, 0xf3, 0xde, 0x26, 0xe9, 0x01, 0xfa, 0x13, 0x13, 0x1b, 0x02, 0xf4, 0x0d, 0x07, 0xfc, 
};

static const uint32_t PredictCount_Median16[] = {
	 9,  9, 15, 13, 11, 12, 12, 13,  5, 14,  8,  7, 10, 13, 10, 13, 
	12, 11,  9, 10, 10,  8,  6, 12,  3,  7, 12,  5, 11,  7, 12, 10, 
	11, 11, 11, 11, 15,  3,  8,  8,  7, 13,  5,  6,  9,  7,  5,  2, 
	 1,  2,  5,  3,  3,  3,  3,  3,  2,  5,  3,  2,  3,  3,  1,  0, 
	 0,  3,  5,  0,  0,  1,  1,  0,  1,  2,  4,  1,  1,  1,  0,  3, 
	 1,  0,  0,  1,  0,  1,  0,  0,  2,  1,  0,  0,  0,  0,  0,  1, 
	 0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0, 
	 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
	 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
	 0,  0,  1,  1,  2,  0,  0,  1,  0,  2,  0,  1,  1,  0,  1,  1, 
	 1,  1,  1,  1,  2,  1,  1,  3,  2,  1,  0,  1,  1,  3,  3,  5, 
	 1,  5,  6,  4,  3,  4,  6,  6,  4,  1,  4,  2,  4,  2,  1,  1, 
	 3,  8,  0,  5,  4, 10,  9,  8,  5,  5,  5, 10,  4,  6,  6,  5, 
	 9,  4,  7,  8,  6,  9,  5,  9,  4, 14,  8, 15,  8,  6,  9,  7, 
	10,  3, 18, 13,  6,  9,  8, 19, 16, 10,  8, 10, 12,  9, 22, 12, 
};

void UnitTest_Predict(void)
{
	typedef void (*PredictLeftFunc)(uint8_t *pDst, const uint8_t *pSrcBegin, const uint8_t *pSrcEnd, uint32_t *pCountTable);
	typedef void (*PredictMedianFunc)(uint8_t *pDst, const uint8_t *pSrcBegin, const uint8_t *pSrcEnd, size_t dwStride, uint32_t *pCountTable);
	typedef void (*RestoreMedianFunc)(uint8_t *pDst, const uint8_t *pSrcBegin, const uint8_t *pSrcEnd, size_t dwStride);

	uint8_t *pSrc;
	uint8_t *pDst;

	pSrc = (uint8_t *)VirtualAlloc(NULL, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	pDst = (uint8_t *)VirtualAlloc(NULL, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);


	PredictLeftFunc pleft1[] = {
		cpp_PredictLeftAndCount,
#ifdef __i386__
		x86_sse2_PredictLeftAndCount_align1,
#endif
#ifdef __x86_64__
		x64_sse2_PredictLeftAndCount_align1,
#endif
		NULL
	};

	for (PredictLeftFunc *fn = pleft1; *fn; fn++) {
		uint32_t count[256];
		memcpy(pSrc + 3, PredictSrc, PredictLen_Left1);
		memset(count, 0, sizeof(count));
		(*fn)(pDst, pSrc + 3, pSrc + 3 + sizeof(PredictSrc), count);
		for (int i = 0; i < PredictLen_Left1; i++)
			_ASSERT(pDst[i] == PredictDst_Left1[i]);
		for (int i = 0; i < _countof(PredictCount_Left1); i++)
			_ASSERT(count[i] == PredictCount_Left1[i]);
	}


	PredictMedianFunc pmed1[] = {
		cpp_PredictMedianAndCount,
#ifdef __i386__
		x86_sse2_PredictMedianAndCount_align1,
#endif
#ifdef __x86_64__
		x64_sse2_PredictMedianAndCount_align1,
#endif
		NULL
	};

	for (PredictMedianFunc *fn = pmed1; *fn; fn++) {
		uint32_t count[256];
		memcpy(pSrc, PredictSrc, PredictWidth_Median1 * PredictHeight_Median1);
		memset(count, 0, sizeof(count));
		(*fn)(pDst, pSrc, pSrc + PredictWidth_Median1 * PredictHeight_Median1, PredictWidth_Median1, count);
		for (int i = 0; i < PredictWidth_Median1 * PredictHeight_Median1; i++)
			_ASSERT(pDst[i] == PredictDst_Median1[i]);
		for (int i = 0; i < _countof(PredictCount_Median1); i++)
			_ASSERT(count[i] == PredictCount_Median1[i]);
	}


	PredictMedianFunc pmed16[] = {
		cpp_PredictMedianAndCount,
#ifdef __i386__
		x86_sse2_PredictMedianAndCount_align16,
#endif
#ifdef __x86_64__
		x64_sse2_PredictMedianAndCount_align16,
#endif
		NULL
	};

	for (PredictMedianFunc *fn = pmed16; *fn; fn++) {
		uint32_t count[256];
		memcpy(pSrc, PredictSrc, PredictWidth_Median16 * PredictHeight_Median16);
		memset(count, 0, sizeof(count));
		(*fn)(pDst, pSrc, pSrc + PredictWidth_Median16 * PredictHeight_Median16, PredictWidth_Median16, count);
		for (int i = 0; i < PredictWidth_Median16 * PredictHeight_Median16; i++)
			_ASSERT(pDst[i] == PredictDst_Median16[i]);
		for (int i = 0; i < _countof(PredictCount_Median16); i++)
			_ASSERT(count[i] == PredictCount_Median16[i]);
	}


	RestoreMedianFunc rmed[] = {
		cpp_RestoreMedian,
#ifdef __i386__
		x86_i686_RestoreMedian_align1,
		x86_sse1mmx_RestoreMedian_align1,
#endif
#ifdef __x86_64__
		x64_sse1mmx_RestoreMedian_align1,
#endif
		NULL
	};

	for (RestoreMedianFunc *fn = rmed; *fn; fn++) {
		memcpy(pSrc, PredictDst_Median16, sizeof(PredictDst_Median16));
		(*fn)(pDst, pSrc, pSrc + PredictWidth_Median16 * PredictHeight_Median16, PredictWidth_Median16);
		for (int i = 0; i < PredictWidth_Median16 * PredictHeight_Median16; i++)
			_ASSERT(pDst[i] == PredictSrc[i]);
	}


	VirtualFree(pSrc, 0, MEM_RELEASE);
	VirtualFree(pDst, 0, MEM_RELEASE);
}

#endif
