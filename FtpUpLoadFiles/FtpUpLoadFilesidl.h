

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Dec 30 17:25:04 2021
 */
/* Compiler settings for FtpUpLoadFiles.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __FtpUpLoadFilesidl_h__
#define __FtpUpLoadFilesidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DFtpUpLoadFiles_FWD_DEFINED__
#define ___DFtpUpLoadFiles_FWD_DEFINED__
typedef interface _DFtpUpLoadFiles _DFtpUpLoadFiles;

#endif 	/* ___DFtpUpLoadFiles_FWD_DEFINED__ */


#ifndef ___DFtpUpLoadFilesEvents_FWD_DEFINED__
#define ___DFtpUpLoadFilesEvents_FWD_DEFINED__
typedef interface _DFtpUpLoadFilesEvents _DFtpUpLoadFilesEvents;

#endif 	/* ___DFtpUpLoadFilesEvents_FWD_DEFINED__ */


#ifndef __FtpUpLoadFiles_FWD_DEFINED__
#define __FtpUpLoadFiles_FWD_DEFINED__

#ifdef __cplusplus
typedef class FtpUpLoadFiles FtpUpLoadFiles;
#else
typedef struct FtpUpLoadFiles FtpUpLoadFiles;
#endif /* __cplusplus */

#endif 	/* __FtpUpLoadFiles_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_FtpUpLoadFiles_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_FtpUpLoadFiles_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_FtpUpLoadFiles_0000_0000_v0_0_s_ifspec;


#ifndef __FtpUpLoadFilesLib_LIBRARY_DEFINED__
#define __FtpUpLoadFilesLib_LIBRARY_DEFINED__

/* library FtpUpLoadFilesLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_FtpUpLoadFilesLib;

#ifndef ___DFtpUpLoadFiles_DISPINTERFACE_DEFINED__
#define ___DFtpUpLoadFiles_DISPINTERFACE_DEFINED__

/* dispinterface _DFtpUpLoadFiles */
/* [uuid] */ 


EXTERN_C const IID DIID__DFtpUpLoadFiles;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5C3172B8-CE50-4DCB-B768-60506BBCB4B6")
    _DFtpUpLoadFiles : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DFtpUpLoadFilesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DFtpUpLoadFiles * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DFtpUpLoadFiles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DFtpUpLoadFiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DFtpUpLoadFiles * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DFtpUpLoadFiles * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DFtpUpLoadFiles * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DFtpUpLoadFiles * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DFtpUpLoadFilesVtbl;

    interface _DFtpUpLoadFiles
    {
        CONST_VTBL struct _DFtpUpLoadFilesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DFtpUpLoadFiles_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DFtpUpLoadFiles_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DFtpUpLoadFiles_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DFtpUpLoadFiles_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DFtpUpLoadFiles_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DFtpUpLoadFiles_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DFtpUpLoadFiles_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DFtpUpLoadFiles_DISPINTERFACE_DEFINED__ */


#ifndef ___DFtpUpLoadFilesEvents_DISPINTERFACE_DEFINED__
#define ___DFtpUpLoadFilesEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DFtpUpLoadFilesEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DFtpUpLoadFilesEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1F0FBEBE-7F6F-4339-8033-B2641403CD5A")
    _DFtpUpLoadFilesEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DFtpUpLoadFilesEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DFtpUpLoadFilesEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DFtpUpLoadFilesEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DFtpUpLoadFilesEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DFtpUpLoadFilesEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DFtpUpLoadFilesEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DFtpUpLoadFilesEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DFtpUpLoadFilesEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DFtpUpLoadFilesEventsVtbl;

    interface _DFtpUpLoadFilesEvents
    {
        CONST_VTBL struct _DFtpUpLoadFilesEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DFtpUpLoadFilesEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DFtpUpLoadFilesEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DFtpUpLoadFilesEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DFtpUpLoadFilesEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DFtpUpLoadFilesEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DFtpUpLoadFilesEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DFtpUpLoadFilesEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DFtpUpLoadFilesEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FtpUpLoadFiles;

#ifdef __cplusplus

class DECLSPEC_UUID("58CAA706-0580-4888-BB5B-447A34C1984F")
FtpUpLoadFiles;
#endif
#endif /* __FtpUpLoadFilesLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


