#ifndef _TIM_H
#define _TIM_H

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <math.h>

#define TIM_OUTPUT_CLUT4	0
#define TIM_OUTPUT_CLUT8	1
#define TIM_OUTPUT_RGB5		2
#define TIM_OUTPUT_RGB24	3

namespace tim {


	// TIM header struct
    typedef struct {

		// ID sub-struct
        struct HEADER_ID {
            unsigned int id:8;     // Always 0x10
            unsigned int ver:8;    // Always 0
            unsigned int pad:16;   // Useless padding
        } id;

		// Flags sub-struct
        struct HEADER_FLAGS {
            unsigned int pmode:3;  // Pixel mode (0: 4-bit, 1: 8-bit, 2:16-bit, 3:24-bit)
            unsigned int clut:1;
            unsigned int pad:24;
        } flags;

    } HEADER;


	// CLUT header struct
    typedef struct {
        unsigned int len;
        unsigned short cx,cy;
        unsigned short cw,ch;
    } CLUT_HEAD;


	// Image data block header
    typedef struct {
        unsigned int len;
        unsigned short x,y;
        unsigned short w,h;
    } IMG_HEAD;


    typedef struct {
        // 0: 4-bit CLUT, 1: 8-bit CLUT, 2:16-bit, 3:24-bit
        int format;
        // Image data params
        void *imgData;
        unsigned short imgWidth,imgHeight;
        unsigned short imgXoffs,imgYoffs;
        // CLUT data params
        void *clutData;
        unsigned short clutWidth,clutHeight;
        unsigned short clutXoffs,clutYoffs;
    } PARAM;


	// RGB5A1 pixel format struct
	typedef struct {
        unsigned short r:5;
        unsigned short g:5;
        unsigned short b:5;
        unsigned short i:1;
    } PIX_RGB5;

    typedef struct {
		unsigned char	r;
		unsigned char	g;
		unsigned char	b;
    } PIX_RGB24;


    /*! tim::ExportFile()
	 *
	 *  /param[in]  fileName - Name of TIM file.
	 *  /param[in]  *param   - tim::PARAM object of TIM export parameters.
	 *
	 *  /returns Zero if the TIM file was written successfully, otherwise an error occured.
	 *
	 */
    int ExportFile(const char* fileName, tim::PARAM *param);

	void FreeParam(tim::PARAM *param);

};


#endif // _TIM_H
