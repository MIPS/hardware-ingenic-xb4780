/* ------------------------------------------------------------------
 * Copyright (C) 1998-2009 PacketVideo
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 * -------------------------------------------------------------------
 */
#ifndef MP_DECODER_H_INCLUDED
#define MP_DECODER_H_INCLUDED

#ifdef __cplusplus
extern "C"{
#include "stream.h"
#include "demuxer.h"
#include "stheader.h"

#include "codec-cfg.h"
#include "avcodec.h"
#include "mp_image.h"
#include "libavutil/mem.h"
#include "intreadwrite.h"
#include "fmt-conversion.h"
#include "codec-cfg.h"
#include "af_format.h"
#include "reorder_ch.h"
//extern int avcodec_initialized;
}
#endif

namespace android{

typedef struct mp_codec_info_s
{
    /* codec long name ("Autodesk FLI/FLC Animation decoder" */
    const char *name;
    /* short name (same as driver name in codecs.conf) ("dshow") */
    const char *short_name;
    /* interface author/maintainer */
    const char *maintainer;
    /* codec author ("Aaron Holtzman <aholtzma@ess.engr.uvic.ca>") */
    const char *author;
    /* any additional comments */
    const char *comment;
} mp_codec_info_t;

typedef mp_codec_info_t ad_info_t;

class mpDecorder{
public:
    mpDecorder(){}
    virtual ~mpDecorder(){}
    virtual int preinit(sh_audio_t *sh){return 0;}
    virtual int init(sh_audio_t *sh){return 0;}
    virtual void uninit(sh_audio_t *sh){};
    virtual int control(sh_audio_t *sh,int cmd,void* arg, ...){return 0;}
    virtual int decode_audio(sh_audio_t *sh_audio,unsigned char **inbuf,int *inlen,unsigned char* outbuf,int *outlen){
	return 0;
    }
};

}
#endif  //#ifndef  MP_DECODER_H_INCLUDED

