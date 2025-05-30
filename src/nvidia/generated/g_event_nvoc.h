
#ifndef _G_EVENT_NVOC_H_
#define _G_EVENT_NVOC_H_

// Version of generated metadata structures
#ifdef NVOC_METADATA_VERSION
#undef NVOC_METADATA_VERSION
#endif
#define NVOC_METADATA_VERSION 2

#include "nvoc/runtime.h"
#include "nvoc/rtti.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * SPDX-FileCopyrightText: Copyright (c) 1993-2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#pragma once
#include "g_event_nvoc.h"

#ifndef _EVENT_H_
#define _EVENT_H_

#include "ctrl/ctrl0000/ctrl0000event.h" // NV0000_NOTIFIERS_MAXCOUNT

#include "resserv/resserv.h"
#include "nvoc/prelude.h"
#include "resserv/rs_server.h"
#include "rmapi/resource.h"
#include "kernel/gpu/gpu_engine_type.h"

// Opaque callback memory type for interfacing the scheduling API
typedef struct TMR_EVENT TMR_EVENT;

struct EVENTNOTIFICATION
{
    NvHandle            hEventClient;
    NvHandle            hEvent;
    NvU32               subdeviceInst;
    NvU32               NotifyIndex;              // NVnnnn_NOTIFIERS_xyz
    NvU32               NotifyType;               // Event class.  NV01_EVENT_OS_EVENT for example.
    NvBool              bUserOsEventHandle;       // Event was allocated from user app.
    NvBool              bBroadcastEvent;          // Wait for all subdevices before sending event.
    NvBool              bClientRM;                // Event was allocated from client RM.
    NvBool              bSubdeviceSpecificEvent;  // SubdeviceSpecificValue is valid.
    NvU32               SubdeviceSpecificValue;   // NV0005_NOTIFY_INDEX_SUBDEVICE
    NvBool              bEventDataRequired;       // nv_post_event allocates memory for Data.
    NvBool              bNonStallIntrEvent;
    NvU32               NotifyTriggerCount;       // Used with bBroadcastEvent.
    NvP64               Data;
    OBJGPU             *pGpu;                     // Store to free dynamic memory on teardown.
    TMR_EVENT          *pTmrEvent;                // Store to free dynamic memory on teardown.
    struct EVENTNOTIFICATION *Next;
};
typedef struct EVENTNOTIFICATION  EVENTNOTIFICATION, *PEVENTNOTIFICATION;


struct INotifier;

#ifndef __NVOC_CLASS_INotifier_TYPEDEF__
#define __NVOC_CLASS_INotifier_TYPEDEF__
typedef struct INotifier INotifier;
#endif /* __NVOC_CLASS_INotifier_TYPEDEF__ */

#ifndef __nvoc_class_id_INotifier
#define __nvoc_class_id_INotifier 0xf8f965
#endif /* __nvoc_class_id_INotifier */



MAKE_LIST(SystemEventQueueList, NV0000_CTRL_GET_SYSTEM_EVENT_DATA_PARAMS);

struct _def_client_system_event_info
{
    SystemEventQueueList eventQueue;
    NvU32                notifyActions[NV0000_NOTIFIERS_MAXCOUNT];
};

/**
 * This class represents data that is shared between one notifier and any
 * events that are registered with the notifier.
 *
 * Instances of this class are ref-counted and will be kept alive until
 * the notifier and all of its events have been freed.
 */

// Private field names are wrapped in PRIVATE_FIELD, which does nothing for
// the matching C source file, but causes diagnostics to be issued if another
// source file references the field.
#ifdef NVOC_EVENT_H_PRIVATE_ACCESS_ALLOWED
#define PRIVATE_FIELD(x) x
#else
#define PRIVATE_FIELD(x) NVOC_PRIVATE_FIELD(x)
#endif


// Metadata with per-class RTTI with ancestor(s)
struct NVOC_METADATA__NotifShare;
struct NVOC_METADATA__RsShared;


struct NotifShare {

    // Metadata starts with RTTI structure.
    union {
         const struct NVOC_METADATA__NotifShare *__nvoc_metadata_ptr;
         const struct NVOC_RTTI *__nvoc_rtti;
    };

    // Parent (i.e. superclass or base class) objects
    struct RsShared __nvoc_base_RsShared;

    // Ancestor object pointers for `staticCast` feature
    struct Object *__nvoc_pbase_Object;    // obj super^2
    struct RsShared *__nvoc_pbase_RsShared;    // shr super
    struct NotifShare *__nvoc_pbase_NotifShare;    // shrnotif

    // Data members
    struct INotifier *pNotifier;
    NvHandle hNotifierClient;
    NvHandle hNotifierResource;
    EVENTNOTIFICATION *pEventList;
};


// Metadata with per-class RTTI with ancestor(s)
struct NVOC_METADATA__NotifShare {
    const struct NVOC_RTTI rtti;
    const struct NVOC_METADATA__RsShared metadata__RsShared;
};

#ifndef __NVOC_CLASS_NotifShare_TYPEDEF__
#define __NVOC_CLASS_NotifShare_TYPEDEF__
typedef struct NotifShare NotifShare;
#endif /* __NVOC_CLASS_NotifShare_TYPEDEF__ */

#ifndef __nvoc_class_id_NotifShare
#define __nvoc_class_id_NotifShare 0xd5f150
#endif /* __nvoc_class_id_NotifShare */

// Casting support
extern const struct NVOC_CLASS_DEF __nvoc_class_def_NotifShare;

#define __staticCast_NotifShare(pThis) \
    ((pThis)->__nvoc_pbase_NotifShare)

#ifdef __nvoc_event_h_disabled
#define __dynamicCast_NotifShare(pThis) ((NotifShare*) NULL)
#else //__nvoc_event_h_disabled
#define __dynamicCast_NotifShare(pThis) \
    ((NotifShare*) __nvoc_dynamicCast(staticCast((pThis), Dynamic), classInfo(NotifShare)))
#endif //__nvoc_event_h_disabled

NV_STATUS __nvoc_objCreateDynamic_NotifShare(NotifShare**, Dynamic*, NvU32, va_list);

NV_STATUS __nvoc_objCreate_NotifShare(NotifShare**, Dynamic*, NvU32);
#define __objCreate_NotifShare(ppNewObj, pParent, createFlags) \
    __nvoc_objCreate_NotifShare((ppNewObj), staticCast((pParent), Dynamic), (createFlags))


// Wrapper macros

// Dispatch functions
NV_STATUS shrnotifConstruct_IMPL(struct NotifShare *arg_pNotifShare);

#define __nvoc_shrnotifConstruct(arg_pNotifShare) shrnotifConstruct_IMPL(arg_pNotifShare)
void shrnotifDestruct_IMPL(struct NotifShare *pNotifShare);

#define __nvoc_shrnotifDestruct(pNotifShare) shrnotifDestruct_IMPL(pNotifShare)
#undef PRIVATE_FIELD


/**
 * This class represents event notification consumers
 */

// Private field names are wrapped in PRIVATE_FIELD, which does nothing for
// the matching C source file, but causes diagnostics to be issued if another
// source file references the field.
#ifdef NVOC_EVENT_H_PRIVATE_ACCESS_ALLOWED
#define PRIVATE_FIELD(x) x
#else
#define PRIVATE_FIELD(x) NVOC_PRIVATE_FIELD(x)
#endif


// Metadata with per-class RTTI and vtable with ancestor(s)
struct NVOC_METADATA__Event;
struct NVOC_METADATA__RmResource;
struct NVOC_VTABLE__Event;


struct Event {

    // Metadata starts with RTTI structure.
    union {
         const struct NVOC_METADATA__Event *__nvoc_metadata_ptr;
         const struct NVOC_RTTI *__nvoc_rtti;
    };

    // Parent (i.e. superclass or base class) objects
    struct RmResource __nvoc_base_RmResource;

    // Ancestor object pointers for `staticCast` feature
    struct Object *__nvoc_pbase_Object;    // obj super^3
    struct RsResource *__nvoc_pbase_RsResource;    // res super^2
    struct RmResourceCommon *__nvoc_pbase_RmResourceCommon;    // rmrescmn super^2
    struct RmResource *__nvoc_pbase_RmResource;    // rmres super
    struct Event *__nvoc_pbase_Event;    // event

    // Data members
    struct NotifShare *pNotifierShare;
    NvHandle hNotifierClient;
    NvHandle hNotifierResource;
    NvHandle hEvent;
};


// Vtable with 21 per-class function pointers
struct NVOC_VTABLE__Event {
    NvBool (*__eventAccessCallback__)(struct Event * /*this*/, struct RsClient *, void *, RsAccessRight);  // virtual inherited (rmres) base (rmres)
    NvBool (*__eventShareCallback__)(struct Event * /*this*/, struct RsClient *, struct RsResourceRef *, RS_SHARE_POLICY *);  // virtual inherited (rmres) base (rmres)
    NV_STATUS (*__eventGetMemInterMapParams__)(struct Event * /*this*/, RMRES_MEM_INTER_MAP_PARAMS *);  // virtual inherited (rmres) base (rmres)
    NV_STATUS (*__eventCheckMemInterUnmap__)(struct Event * /*this*/, NvBool);  // virtual inherited (rmres) base (rmres)
    NV_STATUS (*__eventGetMemoryMappingDescriptor__)(struct Event * /*this*/, struct MEMORY_DESCRIPTOR **);  // virtual inherited (rmres) base (rmres)
    NV_STATUS (*__eventControlSerialization_Prologue__)(struct Event * /*this*/, struct CALL_CONTEXT *, struct RS_RES_CONTROL_PARAMS_INTERNAL *);  // virtual inherited (rmres) base (rmres)
    void (*__eventControlSerialization_Epilogue__)(struct Event * /*this*/, struct CALL_CONTEXT *, struct RS_RES_CONTROL_PARAMS_INTERNAL *);  // virtual inherited (rmres) base (rmres)
    NV_STATUS (*__eventControl_Prologue__)(struct Event * /*this*/, struct CALL_CONTEXT *, struct RS_RES_CONTROL_PARAMS_INTERNAL *);  // virtual inherited (rmres) base (rmres)
    void (*__eventControl_Epilogue__)(struct Event * /*this*/, struct CALL_CONTEXT *, struct RS_RES_CONTROL_PARAMS_INTERNAL *);  // virtual inherited (rmres) base (rmres)
    NvBool (*__eventCanCopy__)(struct Event * /*this*/);  // virtual inherited (res) base (rmres)
    NV_STATUS (*__eventIsDuplicate__)(struct Event * /*this*/, NvHandle, NvBool *);  // virtual inherited (res) base (rmres)
    void (*__eventPreDestruct__)(struct Event * /*this*/);  // virtual inherited (res) base (rmres)
    NV_STATUS (*__eventControl__)(struct Event * /*this*/, struct CALL_CONTEXT *, struct RS_RES_CONTROL_PARAMS_INTERNAL *);  // virtual inherited (res) base (rmres)
    NV_STATUS (*__eventControlFilter__)(struct Event * /*this*/, struct CALL_CONTEXT *, struct RS_RES_CONTROL_PARAMS_INTERNAL *);  // virtual inherited (res) base (rmres)
    NV_STATUS (*__eventMap__)(struct Event * /*this*/, struct CALL_CONTEXT *, RS_CPU_MAP_PARAMS *, RsCpuMapping *);  // virtual inherited (res) base (rmres)
    NV_STATUS (*__eventUnmap__)(struct Event * /*this*/, struct CALL_CONTEXT *, RsCpuMapping *);  // virtual inherited (res) base (rmres)
    NvBool (*__eventIsPartialUnmapSupported__)(struct Event * /*this*/);  // inline virtual inherited (res) base (rmres) body
    NV_STATUS (*__eventMapTo__)(struct Event * /*this*/, RS_RES_MAP_TO_PARAMS *);  // virtual inherited (res) base (rmres)
    NV_STATUS (*__eventUnmapFrom__)(struct Event * /*this*/, RS_RES_UNMAP_FROM_PARAMS *);  // virtual inherited (res) base (rmres)
    NvU32 (*__eventGetRefCount__)(struct Event * /*this*/);  // virtual inherited (res) base (rmres)
    void (*__eventAddAdditionalDependants__)(struct RsClient *, struct Event * /*this*/, RsResourceRef *);  // virtual inherited (res) base (rmres)
};

// Metadata with per-class RTTI and vtable with ancestor(s)
struct NVOC_METADATA__Event {
    const struct NVOC_RTTI rtti;
    const struct NVOC_METADATA__RmResource metadata__RmResource;
    const struct NVOC_VTABLE__Event vtable;
};

#ifndef __NVOC_CLASS_Event_TYPEDEF__
#define __NVOC_CLASS_Event_TYPEDEF__
typedef struct Event Event;
#endif /* __NVOC_CLASS_Event_TYPEDEF__ */

#ifndef __nvoc_class_id_Event
#define __nvoc_class_id_Event 0xa4ecfc
#endif /* __nvoc_class_id_Event */

// Casting support
extern const struct NVOC_CLASS_DEF __nvoc_class_def_Event;

#define __staticCast_Event(pThis) \
    ((pThis)->__nvoc_pbase_Event)

#ifdef __nvoc_event_h_disabled
#define __dynamicCast_Event(pThis) ((Event*) NULL)
#else //__nvoc_event_h_disabled
#define __dynamicCast_Event(pThis) \
    ((Event*) __nvoc_dynamicCast(staticCast((pThis), Dynamic), classInfo(Event)))
#endif //__nvoc_event_h_disabled

NV_STATUS __nvoc_objCreateDynamic_Event(Event**, Dynamic*, NvU32, va_list);

NV_STATUS __nvoc_objCreate_Event(Event**, Dynamic*, NvU32, struct CALL_CONTEXT *arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL *arg_pParams);
#define __objCreate_Event(ppNewObj, pParent, createFlags, arg_pCallContext, arg_pParams) \
    __nvoc_objCreate_Event((ppNewObj), staticCast((pParent), Dynamic), (createFlags), arg_pCallContext, arg_pParams)


// Wrapper macros
#define eventAccessCallback_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_metadata_ptr->vtable.__rmresAccessCallback__
#define eventAccessCallback(pResource, pInvokingClient, pAllocParams, accessRight) eventAccessCallback_DISPATCH(pResource, pInvokingClient, pAllocParams, accessRight)
#define eventShareCallback_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_metadata_ptr->vtable.__rmresShareCallback__
#define eventShareCallback(pResource, pInvokingClient, pParentRef, pSharePolicy) eventShareCallback_DISPATCH(pResource, pInvokingClient, pParentRef, pSharePolicy)
#define eventGetMemInterMapParams_FNPTR(pRmResource) pRmResource->__nvoc_base_RmResource.__nvoc_metadata_ptr->vtable.__rmresGetMemInterMapParams__
#define eventGetMemInterMapParams(pRmResource, pParams) eventGetMemInterMapParams_DISPATCH(pRmResource, pParams)
#define eventCheckMemInterUnmap_FNPTR(pRmResource) pRmResource->__nvoc_base_RmResource.__nvoc_metadata_ptr->vtable.__rmresCheckMemInterUnmap__
#define eventCheckMemInterUnmap(pRmResource, bSubdeviceHandleProvided) eventCheckMemInterUnmap_DISPATCH(pRmResource, bSubdeviceHandleProvided)
#define eventGetMemoryMappingDescriptor_FNPTR(pRmResource) pRmResource->__nvoc_base_RmResource.__nvoc_metadata_ptr->vtable.__rmresGetMemoryMappingDescriptor__
#define eventGetMemoryMappingDescriptor(pRmResource, ppMemDesc) eventGetMemoryMappingDescriptor_DISPATCH(pRmResource, ppMemDesc)
#define eventControlSerialization_Prologue_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_metadata_ptr->vtable.__rmresControlSerialization_Prologue__
#define eventControlSerialization_Prologue(pResource, pCallContext, pParams) eventControlSerialization_Prologue_DISPATCH(pResource, pCallContext, pParams)
#define eventControlSerialization_Epilogue_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_metadata_ptr->vtable.__rmresControlSerialization_Epilogue__
#define eventControlSerialization_Epilogue(pResource, pCallContext, pParams) eventControlSerialization_Epilogue_DISPATCH(pResource, pCallContext, pParams)
#define eventControl_Prologue_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_metadata_ptr->vtable.__rmresControl_Prologue__
#define eventControl_Prologue(pResource, pCallContext, pParams) eventControl_Prologue_DISPATCH(pResource, pCallContext, pParams)
#define eventControl_Epilogue_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_metadata_ptr->vtable.__rmresControl_Epilogue__
#define eventControl_Epilogue(pResource, pCallContext, pParams) eventControl_Epilogue_DISPATCH(pResource, pCallContext, pParams)
#define eventCanCopy_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_metadata_ptr->vtable.__resCanCopy__
#define eventCanCopy(pResource) eventCanCopy_DISPATCH(pResource)
#define eventIsDuplicate_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_metadata_ptr->vtable.__resIsDuplicate__
#define eventIsDuplicate(pResource, hMemory, pDuplicate) eventIsDuplicate_DISPATCH(pResource, hMemory, pDuplicate)
#define eventPreDestruct_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_metadata_ptr->vtable.__resPreDestruct__
#define eventPreDestruct(pResource) eventPreDestruct_DISPATCH(pResource)
#define eventControl_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_metadata_ptr->vtable.__resControl__
#define eventControl(pResource, pCallContext, pParams) eventControl_DISPATCH(pResource, pCallContext, pParams)
#define eventControlFilter_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_metadata_ptr->vtable.__resControlFilter__
#define eventControlFilter(pResource, pCallContext, pParams) eventControlFilter_DISPATCH(pResource, pCallContext, pParams)
#define eventMap_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_metadata_ptr->vtable.__resMap__
#define eventMap(pResource, pCallContext, pParams, pCpuMapping) eventMap_DISPATCH(pResource, pCallContext, pParams, pCpuMapping)
#define eventUnmap_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_metadata_ptr->vtable.__resUnmap__
#define eventUnmap(pResource, pCallContext, pCpuMapping) eventUnmap_DISPATCH(pResource, pCallContext, pCpuMapping)
#define eventIsPartialUnmapSupported_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_metadata_ptr->vtable.__resIsPartialUnmapSupported__
#define eventIsPartialUnmapSupported(pResource) eventIsPartialUnmapSupported_DISPATCH(pResource)
#define eventMapTo_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_metadata_ptr->vtable.__resMapTo__
#define eventMapTo(pResource, pParams) eventMapTo_DISPATCH(pResource, pParams)
#define eventUnmapFrom_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_metadata_ptr->vtable.__resUnmapFrom__
#define eventUnmapFrom(pResource, pParams) eventUnmapFrom_DISPATCH(pResource, pParams)
#define eventGetRefCount_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_metadata_ptr->vtable.__resGetRefCount__
#define eventGetRefCount(pResource) eventGetRefCount_DISPATCH(pResource)
#define eventAddAdditionalDependants_FNPTR(pResource) pResource->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_metadata_ptr->vtable.__resAddAdditionalDependants__
#define eventAddAdditionalDependants(pClient, pResource, pReference) eventAddAdditionalDependants_DISPATCH(pClient, pResource, pReference)

// Dispatch functions
static inline NvBool eventAccessCallback_DISPATCH(struct Event *pResource, struct RsClient *pInvokingClient, void *pAllocParams, RsAccessRight accessRight) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventAccessCallback__(pResource, pInvokingClient, pAllocParams, accessRight);
}

static inline NvBool eventShareCallback_DISPATCH(struct Event *pResource, struct RsClient *pInvokingClient, struct RsResourceRef *pParentRef, RS_SHARE_POLICY *pSharePolicy) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventShareCallback__(pResource, pInvokingClient, pParentRef, pSharePolicy);
}

static inline NV_STATUS eventGetMemInterMapParams_DISPATCH(struct Event *pRmResource, RMRES_MEM_INTER_MAP_PARAMS *pParams) {
    return pRmResource->__nvoc_metadata_ptr->vtable.__eventGetMemInterMapParams__(pRmResource, pParams);
}

static inline NV_STATUS eventCheckMemInterUnmap_DISPATCH(struct Event *pRmResource, NvBool bSubdeviceHandleProvided) {
    return pRmResource->__nvoc_metadata_ptr->vtable.__eventCheckMemInterUnmap__(pRmResource, bSubdeviceHandleProvided);
}

static inline NV_STATUS eventGetMemoryMappingDescriptor_DISPATCH(struct Event *pRmResource, struct MEMORY_DESCRIPTOR **ppMemDesc) {
    return pRmResource->__nvoc_metadata_ptr->vtable.__eventGetMemoryMappingDescriptor__(pRmResource, ppMemDesc);
}

static inline NV_STATUS eventControlSerialization_Prologue_DISPATCH(struct Event *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventControlSerialization_Prologue__(pResource, pCallContext, pParams);
}

static inline void eventControlSerialization_Epilogue_DISPATCH(struct Event *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    pResource->__nvoc_metadata_ptr->vtable.__eventControlSerialization_Epilogue__(pResource, pCallContext, pParams);
}

static inline NV_STATUS eventControl_Prologue_DISPATCH(struct Event *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventControl_Prologue__(pResource, pCallContext, pParams);
}

static inline void eventControl_Epilogue_DISPATCH(struct Event *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    pResource->__nvoc_metadata_ptr->vtable.__eventControl_Epilogue__(pResource, pCallContext, pParams);
}

static inline NvBool eventCanCopy_DISPATCH(struct Event *pResource) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventCanCopy__(pResource);
}

static inline NV_STATUS eventIsDuplicate_DISPATCH(struct Event *pResource, NvHandle hMemory, NvBool *pDuplicate) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventIsDuplicate__(pResource, hMemory, pDuplicate);
}

static inline void eventPreDestruct_DISPATCH(struct Event *pResource) {
    pResource->__nvoc_metadata_ptr->vtable.__eventPreDestruct__(pResource);
}

static inline NV_STATUS eventControl_DISPATCH(struct Event *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventControl__(pResource, pCallContext, pParams);
}

static inline NV_STATUS eventControlFilter_DISPATCH(struct Event *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventControlFilter__(pResource, pCallContext, pParams);
}

static inline NV_STATUS eventMap_DISPATCH(struct Event *pResource, struct CALL_CONTEXT *pCallContext, RS_CPU_MAP_PARAMS *pParams, RsCpuMapping *pCpuMapping) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventMap__(pResource, pCallContext, pParams, pCpuMapping);
}

static inline NV_STATUS eventUnmap_DISPATCH(struct Event *pResource, struct CALL_CONTEXT *pCallContext, RsCpuMapping *pCpuMapping) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventUnmap__(pResource, pCallContext, pCpuMapping);
}

static inline NvBool eventIsPartialUnmapSupported_DISPATCH(struct Event *pResource) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventIsPartialUnmapSupported__(pResource);
}

static inline NV_STATUS eventMapTo_DISPATCH(struct Event *pResource, RS_RES_MAP_TO_PARAMS *pParams) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventMapTo__(pResource, pParams);
}

static inline NV_STATUS eventUnmapFrom_DISPATCH(struct Event *pResource, RS_RES_UNMAP_FROM_PARAMS *pParams) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventUnmapFrom__(pResource, pParams);
}

static inline NvU32 eventGetRefCount_DISPATCH(struct Event *pResource) {
    return pResource->__nvoc_metadata_ptr->vtable.__eventGetRefCount__(pResource);
}

static inline void eventAddAdditionalDependants_DISPATCH(struct RsClient *pClient, struct Event *pResource, RsResourceRef *pReference) {
    pResource->__nvoc_metadata_ptr->vtable.__eventAddAdditionalDependants__(pClient, pResource, pReference);
}

NV_STATUS eventConstruct_IMPL(struct Event *arg_pEvent, struct CALL_CONTEXT *arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL *arg_pParams);

#define __nvoc_eventConstruct(arg_pEvent, arg_pCallContext, arg_pParams) eventConstruct_IMPL(arg_pEvent, arg_pCallContext, arg_pParams)
void eventDestruct_IMPL(struct Event *pEvent);

#define __nvoc_eventDestruct(pEvent) eventDestruct_IMPL(pEvent)
NV_STATUS eventInit_IMPL(struct Event *pEvent, struct CALL_CONTEXT *pCallContext, NvHandle hNotifierClient, NvHandle hNotifierResource, PEVENTNOTIFICATION **pppEventNotification);

#ifdef __nvoc_event_h_disabled
static inline NV_STATUS eventInit(struct Event *pEvent, struct CALL_CONTEXT *pCallContext, NvHandle hNotifierClient, NvHandle hNotifierResource, PEVENTNOTIFICATION **pppEventNotification) {
    NV_ASSERT_FAILED_PRECOMP("Event was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_event_h_disabled
#define eventInit(pEvent, pCallContext, hNotifierClient, hNotifierResource, pppEventNotification) eventInit_IMPL(pEvent, pCallContext, hNotifierClient, hNotifierResource, pppEventNotification)
#endif //__nvoc_event_h_disabled

NV_STATUS eventGetByHandle_IMPL(struct RsClient *pClient, NvHandle hEvent, NvU32 *pNotifyIndex);

#define eventGetByHandle(pClient, hEvent, pNotifyIndex) eventGetByHandle_IMPL(pClient, hEvent, pNotifyIndex)
#undef PRIVATE_FIELD


/**
  * Mix-in interface for resources that send notifications to events
  */

// Private field names are wrapped in PRIVATE_FIELD, which does nothing for
// the matching C source file, but causes diagnostics to be issued if another
// source file references the field.
#ifdef NVOC_EVENT_H_PRIVATE_ACCESS_ALLOWED
#define PRIVATE_FIELD(x) x
#else
#define PRIVATE_FIELD(x) NVOC_PRIVATE_FIELD(x)
#endif


// Metadata with per-class RTTI and vtable
struct NVOC_METADATA__INotifier;
struct NVOC_VTABLE__INotifier;


struct INotifier {

    // Metadata starts with RTTI structure.
    union {
         const struct NVOC_METADATA__INotifier *__nvoc_metadata_ptr;
         const struct NVOC_RTTI *__nvoc_rtti;
    };

    // Ancestor object pointers for `staticCast` feature
    struct INotifier *__nvoc_pbase_INotifier;    // inotify
};


// Vtable with 5 per-class function pointers
struct NVOC_VTABLE__INotifier {
    PEVENTNOTIFICATION * (*__inotifyGetNotificationListPtr__)(struct INotifier * /*this*/);  // pure virtual
    void (*__inotifySetNotificationShare__)(struct INotifier * /*this*/, struct NotifShare *);  // pure virtual
    struct NotifShare * (*__inotifyGetNotificationShare__)(struct INotifier * /*this*/);  // pure virtual
    NV_STATUS (*__inotifyUnregisterEvent__)(struct INotifier * /*this*/, NvHandle, NvHandle, NvHandle, NvHandle);  // pure virtual
    NV_STATUS (*__inotifyGetOrAllocNotifShare__)(struct INotifier * /*this*/, NvHandle, NvHandle, struct NotifShare **);  // pure virtual
};

// Metadata with per-class RTTI and vtable
struct NVOC_METADATA__INotifier {
    const struct NVOC_RTTI rtti;
    const struct NVOC_VTABLE__INotifier vtable;
};

#ifndef __NVOC_CLASS_INotifier_TYPEDEF__
#define __NVOC_CLASS_INotifier_TYPEDEF__
typedef struct INotifier INotifier;
#endif /* __NVOC_CLASS_INotifier_TYPEDEF__ */

#ifndef __nvoc_class_id_INotifier
#define __nvoc_class_id_INotifier 0xf8f965
#endif /* __nvoc_class_id_INotifier */

// Casting support
extern const struct NVOC_CLASS_DEF __nvoc_class_def_INotifier;

#define __staticCast_INotifier(pThis) \
    ((pThis)->__nvoc_pbase_INotifier)

#ifdef __nvoc_event_h_disabled
#define __dynamicCast_INotifier(pThis) ((INotifier*) NULL)
#else //__nvoc_event_h_disabled
#define __dynamicCast_INotifier(pThis) \
    ((INotifier*) __nvoc_dynamicCast(staticCast((pThis), Dynamic), classInfo(INotifier)))
#endif //__nvoc_event_h_disabled

NV_STATUS __nvoc_objCreateDynamic_INotifier(INotifier**, Dynamic*, NvU32, va_list);

NV_STATUS __nvoc_objCreate_INotifier(INotifier**, Dynamic*, NvU32, struct CALL_CONTEXT *arg_pCallContext);
#define __objCreate_INotifier(ppNewObj, pParent, createFlags, arg_pCallContext) \
    __nvoc_objCreate_INotifier((ppNewObj), staticCast((pParent), Dynamic), (createFlags), arg_pCallContext)


// Wrapper macros
#define inotifyGetNotificationListPtr_FNPTR(pNotifier) pNotifier->__nvoc_metadata_ptr->vtable.__inotifyGetNotificationListPtr__
#define inotifyGetNotificationListPtr(pNotifier) inotifyGetNotificationListPtr_DISPATCH(pNotifier)
#define inotifySetNotificationShare_FNPTR(pNotifier) pNotifier->__nvoc_metadata_ptr->vtable.__inotifySetNotificationShare__
#define inotifySetNotificationShare(pNotifier, pNotifShare) inotifySetNotificationShare_DISPATCH(pNotifier, pNotifShare)
#define inotifyGetNotificationShare_FNPTR(pNotifier) pNotifier->__nvoc_metadata_ptr->vtable.__inotifyGetNotificationShare__
#define inotifyGetNotificationShare(pNotifier) inotifyGetNotificationShare_DISPATCH(pNotifier)
#define inotifyUnregisterEvent_FNPTR(pNotifier) pNotifier->__nvoc_metadata_ptr->vtable.__inotifyUnregisterEvent__
#define inotifyUnregisterEvent(pNotifier, hNotifierClient, hNotifierResource, hEventClient, hEvent) inotifyUnregisterEvent_DISPATCH(pNotifier, hNotifierClient, hNotifierResource, hEventClient, hEvent)
#define inotifyGetOrAllocNotifShare_FNPTR(pNotifier) pNotifier->__nvoc_metadata_ptr->vtable.__inotifyGetOrAllocNotifShare__
#define inotifyGetOrAllocNotifShare(pNotifier, hNotifierClient, hNotifierResource, ppNotifShare) inotifyGetOrAllocNotifShare_DISPATCH(pNotifier, hNotifierClient, hNotifierResource, ppNotifShare)

// Dispatch functions
static inline PEVENTNOTIFICATION * inotifyGetNotificationListPtr_DISPATCH(struct INotifier *pNotifier) {
    return pNotifier->__nvoc_metadata_ptr->vtable.__inotifyGetNotificationListPtr__(pNotifier);
}

static inline void inotifySetNotificationShare_DISPATCH(struct INotifier *pNotifier, struct NotifShare *pNotifShare) {
    pNotifier->__nvoc_metadata_ptr->vtable.__inotifySetNotificationShare__(pNotifier, pNotifShare);
}

static inline struct NotifShare * inotifyGetNotificationShare_DISPATCH(struct INotifier *pNotifier) {
    return pNotifier->__nvoc_metadata_ptr->vtable.__inotifyGetNotificationShare__(pNotifier);
}

static inline NV_STATUS inotifyUnregisterEvent_DISPATCH(struct INotifier *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, NvHandle hEventClient, NvHandle hEvent) {
    return pNotifier->__nvoc_metadata_ptr->vtable.__inotifyUnregisterEvent__(pNotifier, hNotifierClient, hNotifierResource, hEventClient, hEvent);
}

static inline NV_STATUS inotifyGetOrAllocNotifShare_DISPATCH(struct INotifier *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, struct NotifShare **ppNotifShare) {
    return pNotifier->__nvoc_metadata_ptr->vtable.__inotifyGetOrAllocNotifShare__(pNotifier, hNotifierClient, hNotifierResource, ppNotifShare);
}

NV_STATUS inotifyConstruct_IMPL(struct INotifier *arg_pNotifier, struct CALL_CONTEXT *arg_pCallContext);

#define __nvoc_inotifyConstruct(arg_pNotifier, arg_pCallContext) inotifyConstruct_IMPL(arg_pNotifier, arg_pCallContext)
void inotifyDestruct_IMPL(struct INotifier *pNotifier);

#define __nvoc_inotifyDestruct(pNotifier) inotifyDestruct_IMPL(pNotifier)
PEVENTNOTIFICATION inotifyGetNotificationList_IMPL(struct INotifier *pNotifier);

#ifdef __nvoc_event_h_disabled
static inline PEVENTNOTIFICATION inotifyGetNotificationList(struct INotifier *pNotifier) {
    NV_ASSERT_FAILED_PRECOMP("INotifier was disabled!");
    return NULL;
}
#else //__nvoc_event_h_disabled
#define inotifyGetNotificationList(pNotifier) inotifyGetNotificationList_IMPL(pNotifier)
#endif //__nvoc_event_h_disabled

#undef PRIVATE_FIELD


/**
  * Basic implementation for event notification mix-in
  */

// Private field names are wrapped in PRIVATE_FIELD, which does nothing for
// the matching C source file, but causes diagnostics to be issued if another
// source file references the field.
#ifdef NVOC_EVENT_H_PRIVATE_ACCESS_ALLOWED
#define PRIVATE_FIELD(x) x
#else
#define PRIVATE_FIELD(x) NVOC_PRIVATE_FIELD(x)
#endif


// Metadata with per-class RTTI and vtable with ancestor(s)
struct NVOC_METADATA__Notifier;
struct NVOC_METADATA__INotifier;
struct NVOC_VTABLE__Notifier;


struct Notifier {

    // Metadata starts with RTTI structure.
    union {
         const struct NVOC_METADATA__Notifier *__nvoc_metadata_ptr;
         const struct NVOC_RTTI *__nvoc_rtti;
    };

    // Parent (i.e. superclass or base class) objects
    struct INotifier __nvoc_base_INotifier;

    // Ancestor object pointers for `staticCast` feature
    struct INotifier *__nvoc_pbase_INotifier;    // inotify super
    struct Notifier *__nvoc_pbase_Notifier;    // notify

    // Data members
    struct NotifShare *pNotifierShare;
};


// Vtable with 5 per-class function pointers
struct NVOC_VTABLE__Notifier {
    PEVENTNOTIFICATION * (*__notifyGetNotificationListPtr__)(struct Notifier * /*this*/);  // virtual override (inotify) base (inotify)
    struct NotifShare * (*__notifyGetNotificationShare__)(struct Notifier * /*this*/);  // virtual override (inotify) base (inotify)
    void (*__notifySetNotificationShare__)(struct Notifier * /*this*/, struct NotifShare *);  // virtual override (inotify) base (inotify)
    NV_STATUS (*__notifyUnregisterEvent__)(struct Notifier * /*this*/, NvHandle, NvHandle, NvHandle, NvHandle);  // virtual override (inotify) base (inotify)
    NV_STATUS (*__notifyGetOrAllocNotifShare__)(struct Notifier * /*this*/, NvHandle, NvHandle, struct NotifShare **);  // virtual override (inotify) base (inotify)
};

// Metadata with per-class RTTI and vtable with ancestor(s)
struct NVOC_METADATA__Notifier {
    const struct NVOC_RTTI rtti;
    const struct NVOC_METADATA__INotifier metadata__INotifier;
    const struct NVOC_VTABLE__Notifier vtable;
};

#ifndef __NVOC_CLASS_Notifier_TYPEDEF__
#define __NVOC_CLASS_Notifier_TYPEDEF__
typedef struct Notifier Notifier;
#endif /* __NVOC_CLASS_Notifier_TYPEDEF__ */

#ifndef __nvoc_class_id_Notifier
#define __nvoc_class_id_Notifier 0xa8683b
#endif /* __nvoc_class_id_Notifier */

// Casting support
extern const struct NVOC_CLASS_DEF __nvoc_class_def_Notifier;

#define __staticCast_Notifier(pThis) \
    ((pThis)->__nvoc_pbase_Notifier)

#ifdef __nvoc_event_h_disabled
#define __dynamicCast_Notifier(pThis) ((Notifier*) NULL)
#else //__nvoc_event_h_disabled
#define __dynamicCast_Notifier(pThis) \
    ((Notifier*) __nvoc_dynamicCast(staticCast((pThis), Dynamic), classInfo(Notifier)))
#endif //__nvoc_event_h_disabled

NV_STATUS __nvoc_objCreateDynamic_Notifier(Notifier**, Dynamic*, NvU32, va_list);

NV_STATUS __nvoc_objCreate_Notifier(Notifier**, Dynamic*, NvU32, struct CALL_CONTEXT *arg_pCallContext);
#define __objCreate_Notifier(ppNewObj, pParent, createFlags, arg_pCallContext) \
    __nvoc_objCreate_Notifier((ppNewObj), staticCast((pParent), Dynamic), (createFlags), arg_pCallContext)


// Wrapper macros
#define notifyGetNotificationListPtr_FNPTR(pNotifier) pNotifier->__nvoc_metadata_ptr->vtable.__notifyGetNotificationListPtr__
#define notifyGetNotificationListPtr(pNotifier) notifyGetNotificationListPtr_DISPATCH(pNotifier)
#define notifyGetNotificationShare_FNPTR(pNotifier) pNotifier->__nvoc_metadata_ptr->vtable.__notifyGetNotificationShare__
#define notifyGetNotificationShare(pNotifier) notifyGetNotificationShare_DISPATCH(pNotifier)
#define notifySetNotificationShare_FNPTR(pNotifier) pNotifier->__nvoc_metadata_ptr->vtable.__notifySetNotificationShare__
#define notifySetNotificationShare(pNotifier, pNotifShare) notifySetNotificationShare_DISPATCH(pNotifier, pNotifShare)
#define notifyUnregisterEvent_FNPTR(pNotifier) pNotifier->__nvoc_metadata_ptr->vtable.__notifyUnregisterEvent__
#define notifyUnregisterEvent(pNotifier, hNotifierClient, hNotifierResource, hEventClient, hEvent) notifyUnregisterEvent_DISPATCH(pNotifier, hNotifierClient, hNotifierResource, hEventClient, hEvent)
#define notifyGetOrAllocNotifShare_FNPTR(pNotifier) pNotifier->__nvoc_metadata_ptr->vtable.__notifyGetOrAllocNotifShare__
#define notifyGetOrAllocNotifShare(pNotifier, hNotifierClient, hNotifierResource, ppNotifShare) notifyGetOrAllocNotifShare_DISPATCH(pNotifier, hNotifierClient, hNotifierResource, ppNotifShare)

// Dispatch functions
static inline PEVENTNOTIFICATION * notifyGetNotificationListPtr_DISPATCH(struct Notifier *pNotifier) {
    return pNotifier->__nvoc_metadata_ptr->vtable.__notifyGetNotificationListPtr__(pNotifier);
}

static inline struct NotifShare * notifyGetNotificationShare_DISPATCH(struct Notifier *pNotifier) {
    return pNotifier->__nvoc_metadata_ptr->vtable.__notifyGetNotificationShare__(pNotifier);
}

static inline void notifySetNotificationShare_DISPATCH(struct Notifier *pNotifier, struct NotifShare *pNotifShare) {
    pNotifier->__nvoc_metadata_ptr->vtable.__notifySetNotificationShare__(pNotifier, pNotifShare);
}

static inline NV_STATUS notifyUnregisterEvent_DISPATCH(struct Notifier *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, NvHandle hEventClient, NvHandle hEvent) {
    return pNotifier->__nvoc_metadata_ptr->vtable.__notifyUnregisterEvent__(pNotifier, hNotifierClient, hNotifierResource, hEventClient, hEvent);
}

static inline NV_STATUS notifyGetOrAllocNotifShare_DISPATCH(struct Notifier *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, struct NotifShare **ppNotifShare) {
    return pNotifier->__nvoc_metadata_ptr->vtable.__notifyGetOrAllocNotifShare__(pNotifier, hNotifierClient, hNotifierResource, ppNotifShare);
}

PEVENTNOTIFICATION *notifyGetNotificationListPtr_IMPL(struct Notifier *pNotifier);

struct NotifShare *notifyGetNotificationShare_IMPL(struct Notifier *pNotifier);

void notifySetNotificationShare_IMPL(struct Notifier *pNotifier, struct NotifShare *pNotifShare);

NV_STATUS notifyUnregisterEvent_IMPL(struct Notifier *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, NvHandle hEventClient, NvHandle hEvent);

NV_STATUS notifyGetOrAllocNotifShare_IMPL(struct Notifier *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, struct NotifShare **ppNotifShare);

NV_STATUS notifyConstruct_IMPL(struct Notifier *arg_pNotifier, struct CALL_CONTEXT *arg_pCallContext);

#define __nvoc_notifyConstruct(arg_pNotifier, arg_pCallContext) notifyConstruct_IMPL(arg_pNotifier, arg_pCallContext)
void notifyDestruct_IMPL(struct Notifier *pNotifier);

#define __nvoc_notifyDestruct(pNotifier) notifyDestruct_IMPL(pNotifier)
#undef PRIVATE_FIELD


void CliAddSystemEvent(NvU32, void *, NvBool *);
void CliDelObjectEvents(RsResourceRef *pResourceRef);
NvBool CliGetEventInfo(NvHandle hClient, NvHandle hEvent, struct Event **ppEvent);
NV_STATUS CliGetEventNotificationList(NvHandle hClient, NvHandle hObject,
                                      struct INotifier **ppNotifier,
                                      PEVENTNOTIFICATION **pppEventNotification);

NV_STATUS registerEventNotification(PEVENTNOTIFICATION*, struct RsClient *, NvHandle, NvHandle, NvU32, NvU32, NvP64, NvBool);
NV_STATUS unregisterEventNotification(PEVENTNOTIFICATION*, NvHandle, NvHandle, NvHandle);
NV_STATUS unregisterEventNotificationWithData(PEVENTNOTIFICATION *, NvHandle, NvHandle, NvHandle, NvBool, NvP64);
NV_STATUS bindEventNotificationToSubdevice(PEVENTNOTIFICATION, NvHandle, NvU32);
NV_STATUS engineNonStallIntrNotify(OBJGPU *, RM_ENGINE_TYPE);
NV_STATUS notifyEvents(OBJGPU*, EVENTNOTIFICATION*, NvU32, NvU32, NvU32, NV_STATUS, NvU32);
NV_STATUS engineNonStallIntrNotifyEvent(OBJGPU *, RM_ENGINE_TYPE, NvHandle);

typedef struct GpuEngineEventNotificationList GpuEngineEventNotificationList;

NV_STATUS gpuEngineEventNotificationListCreate(OBJGPU *, GpuEngineEventNotificationList **);
void      gpuEngineEventNotificationListDestroy(OBJGPU *, GpuEngineEventNotificationList *);

// System Event Queue helpers
void eventSystemInitEventQueue(SystemEventQueueList *pQueue);
NV_STATUS eventSystemEnqueueEvent(SystemEventQueueList *pQueue, NvU32 event, void *pEventData);
NV_STATUS eventSystemDequeueEvent(SystemEventQueueList *pQueue, NV0000_CTRL_GET_SYSTEM_EVENT_DATA_PARAMS *pEvent);
void eventSystemClearEventQueue(SystemEventQueueList *pQueue);

#endif // _EVENT_H_

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _G_EVENT_NVOC_H_
