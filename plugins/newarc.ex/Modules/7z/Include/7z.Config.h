#include "7z.h"

#define countof(x) (sizeof(x)/sizeof(x[0]))

enum CompressionLevel
{
	kStore = 0,
	kFastest = 1,
	kFast = 3,
	kNormal = 5,
	kMaximum = 7,
	kUltra = 9
};

enum CompressionMethodID
{
	kCopy,
	kLZMA,
	kLZMA2,
	kPPMd,
	kBZip2,
	kDeflate,
	kDeflate64
};


static const TCHAR* MethodNames[] =
{
	_T("Copy"),
	_T("LZMA"),
	_T("LZMA2"),
	_T("PPMd"),
	_T("BZip2"),
	_T("Deflate"),
	_T("Deflate64")
};


static const TCHAR* LevelNames[] =
{
	_T("Store"),
	_T("Fastest"),
	NULL,
	_T("Fast"),
	NULL,
	_T("Normal"),
	NULL,
	_T("Maximum"),
	NULL,
	_T("Ultra")
};

static const CompressionMethodID SevenZipMethods[] = {kLZMA, kLZMA2, kPPMd, kBZip2};
static const CompressionMethodID SevenZipSfxMethods[] = {kCopy, kLZMA, kLZMA2, kPPMd};
static const CompressionMethodID ZipMethods[] = {kDeflate, kDeflate64, kBZip2, kLZMA};
static const CompressionMethodID GZipMethods[] = {kDeflate};
static const CompressionMethodID BZip2Methods[] = {kBZip2};
static const CompressionMethodID XzMethods[] = {kLZMA2};

struct CompressionFormatInfo
{
	const TCHAR* lpName;
	DWORD dwLevelMask;
	const CompressionMethodID* pMethodIDs;
	int nNumMethods;
	bool SupportFilter;
	bool SupportSolid;
	bool SupportMultiThread;
	bool SupportSFX;
	bool SupportEncrypt;
	bool SupportEncryptFileNames;
	bool SupportVolumes;
};

static const CompressionFormatInfo CompressionFormats[] =
{
	{	
		_T("7z"), 
		(1 << 0) | (1 << 1) | (1 << 3) | (1 << 5) | (1 << 7) | (1 << 9),
		SevenZipMethods,
		countof(SevenZipMethods),
		true,
		true,
		true,
		true,
		true,
		true,
		true
	},
	{
		_T("7zSFX"),
		(1 << 0) | (1 << 1) | (1 << 3) | (1 << 5) | (1 << 7) | (1 << 9),
		SevenZipSfxMethods,
		countof(SevenZipSfxMethods),
		true,
		true,
		true,
		true,
		true,
		true,
		true
	},
	{
		_T("Zip"),
		(1 << 0) | (1 << 1) | (1 << 3) | (1 << 5) | (1 << 7) | (1 << 9),
		ZipMethods,
		countof(ZipMethods),
		false, 
		false, 
		true, 
		false, 
		true, 
		false,
		false
	},
	{
		_T("GZip"),
		(1 << 1) | (1 << 5) | (1 << 7) | (1 << 9),
		GZipMethods,
		countof(GZipMethods),
		false, 
		false, 
		false, 
		false, 
		false, 
		false,
		false
	},
	{
		_T("BZip2"),
		(1 << 1) | (1 << 3) | (1 << 5) | (1 << 7) | (1 << 9),
		BZip2Methods,
		countof(BZip2Methods),
		false, 
		false, 
		true, 
		false, 
		false, 
		false,
		false
	},
	{
		_T("xz"),
		(1 << 1) | (1 << 3) | (1 << 5) | (1 << 7) | (1 << 9),
		XzMethods,
		countof(XzMethods),
		false, 
		false, 
		true, 
		false, 
		false, 
		false,
		false
	},
	{
		_T("Tar"),
		(1 << 0),
		0, 
		0,
		false, 
		false, 
		false, 
		false, 
		false, 
		false,
		false
	}
};

struct CompressionMapEntry 
{
	const GUID& uid;
	const CompressionFormatInfo* Format;
};

static CompressionMapEntry CompressionMap[] = 
{
	{CLSID_CFormat7z, &CompressionFormats[0]},
	{CLSID_CZipHandler, &CompressionFormats[2]},
	{CLSID_CGZipHandler, &CompressionFormats[3]},
	{CLSID_CBZip2Handler, &CompressionFormats[4]},
	{CLSID_CXzHandler, &CompressionFormats[5]},
	{CLSID_CTarHandler, &CompressionFormats[6]}
};


class SevenZipCompressionConfig {

public:
	const CompressionFormatInfo* pFormat;

	int nLevel;

	bool bOverride;

	int nMethod;
	unsigned int uDictionarySize;

	bool bFilter;
	bool bSolid;
	bool bMultithread;
	bool bSFX;
	bool bEncrypt;
	bool bEncryptFileNames;

	bool bCompressHeaders;
	bool bCompressHeadersFull;

	bool bVolumeMode;

public:

	void ToString(string& strResult);
	void FromString(string strResult);
};

extern const CompressionFormatInfo* GetCompressionFormatInfo(const GUID& uid);
extern bool dlgSevenZipPluginConfigure(SevenZipCompressionConfig* pCfg);