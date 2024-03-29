/* �����R�[�h�͂r�i�h�r ���s�R�[�h�͂b�q�k�e */
/* $Id: ULY0Codec.h 870 2012-04-21 14:16:44Z umezawa $ */

#pragma once
#include "Codec.h"
#include "UL00Codec.h"
#include "FrameBuffer.h"
#include "Thread.h"
#include "HuffmanCode.h"

class CULY0Codec :
	public CUL00Codec
{
private:
	static const utvf_t m_utvfEncoderInput[];
	static const utvf_t m_utvfDecoderOutput[];
	static const utvf_t m_utvfCompressed[];

public:
	CULY0Codec(const char *pszInterfaceName);
	virtual ~CULY0Codec(void);
	static CCodec *CreateInstance(const char *pszInterfaceName);

public:
	virtual const utvf_t *GetEncoderInputFormat(void) { return m_utvfEncoderInput; }
	virtual const utvf_t *GetDecoderOutputFormat(void) { return m_utvfDecoderOutput; }
	virtual const utvf_t *GetCompressedFormat(void) { return m_utvfCompressed; }

private:
	void ConvertBottomupRGBToULY0(uint8_t *pDstYBegin, uint8_t *pDstUBegin, uint8_t *pDstVBegin, uint32_t nBandIndex, uint32_t bypp);
	void ConvertTopdownRGBToULY0(uint8_t *pDstYBegin, uint8_t *pDstUBegin, uint8_t *pDstVBegin, uint32_t nBandIndex, uint32_t bypp);
	void ConvertYUV422ToULY0(uint8_t *pDstYBegin, uint8_t *pDstUBegin, uint8_t *pDstVBegin, uint32_t nBandIndex, uint32_t nYOffset);
	void ConvertULY0ToBottomupRGB(const uint8_t *pSrcYBegin, const uint8_t *pSrcUBegin, const uint8_t *pSrcVBegin, uint32_t nBandIndex, uint32_t bypp);
	void ConvertULY0ToTopdownRGB(const uint8_t *pSrcYBegin, const uint8_t *pSrcUBegin, const uint8_t *pSrcVBegin, uint32_t nBandIndex, uint32_t bypp);
	void ConvertULY0ToYUV422(const uint8_t *pSrcYBegin, const uint8_t *pSrcUBegin, const uint8_t *pSrcVBegin, uint32_t nBandIndex, uint32_t nYOffset);

protected:
	virtual const char *GetColorFormatName(void) { return "YUV420"; }
	virtual int GetRealBitCount(void) { return 12; }
	virtual int GetNumPlanes(void) { return 3; }
	virtual void CalcPlaneSizes(unsigned int width, unsigned int height);
	virtual void ConvertToPlanar(uint32_t nBandIndex);
	virtual int GetMacroPixelWidth(void) { return 2; }
	virtual int GetMacroPixelHeight(void) { return 2; }

	virtual void ConvertFromPlanar(uint32_t nBandIndex);
	virtual bool DecodeDirect(uint32_t nBandIndex);
};
