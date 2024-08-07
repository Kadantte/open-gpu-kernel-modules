// Generated by the protocol buffer compiler.  DO NOT EDIT!

#include "nvtypes.h"
#include "prbrt.h"
#include "g_engines_pb.h"

// 'Mc' field defaults

// 'Mc' field descriptors
const PRB_FIELD_DESC prb_fields_nvdebug_eng_mc[] = {
    {
        1,
        {
            PRB_OPTIONAL,
            PRB_MESSAGE,
            0,
        },
        NVDEBUG_ENG_MC_RMDATA,
        0,
        PRB_MAYBE_FIELD_NAME("rm_data")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        2,
        {
            PRB_REPEATED,
            PRB_MESSAGE,
            0,
        },
        NVDEBUG_ENG_MC_PCIBARINFO,
        0,
        PRB_MAYBE_FIELD_NAME("pci_bars")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        3,
        {
            PRB_REPEATED,
            PRB_MESSAGE,
            0,
        },
        REGS_REGSANDMEM,
        0,
        PRB_MAYBE_FIELD_NAME("regs")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
};

// 'Gpu' field defaults

// 'Gpu' field descriptors
const PRB_FIELD_DESC prb_fields_nvdebug_eng_gpu[] = {
    {
        1,
        {
            PRB_OPTIONAL,
            PRB_UINT32,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("gpu_id")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        2,
        {
            PRB_OPTIONAL,
            PRB_BOOL,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("is_sli")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        3,
        {
            PRB_OPTIONAL,
            PRB_BOOL,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("is_notebook")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        4,
        {
            PRB_OPTIONAL,
            PRB_BOOL,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("is_virtual")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        5,
        {
            PRB_OPTIONAL,
            PRB_BOOL,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("is_full_power")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        6,
        {
            PRB_OPTIONAL,
            PRB_BOOL,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("is_in_fullchip_reset")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        7,
        {
            PRB_OPTIONAL,
            PRB_BOOL,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("is_in_sec_bus_reset")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        8,
        {
            PRB_OPTIONAL,
            PRB_BOOL,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("is_in_gc6_reset")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        9,
        {
            PRB_OPTIONAL,
            PRB_BOOL,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("is_suspended")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        10,
        {
            PRB_OPTIONAL,
            PRB_BOOL,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("is_lost")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        11,
        {
            PRB_OPTIONAL,
            PRB_BOOL,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("is_accessible")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        37,
        {
            PRB_REPEATED,
            PRB_MESSAGE,
            0,
        },
        REGS_REGSANDMEM,
        0,
        PRB_MAYBE_FIELD_NAME("regs")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        39,
        {
            PRB_OPTIONAL,
            PRB_UINT32,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("rusd_mask")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
};

// 'Nvd' field defaults

// 'Nvd' field descriptors
const PRB_FIELD_DESC prb_fields_nvdebug_eng_nvd[] = {
    {
        1,
        {
            PRB_REPEATED,
            PRB_MESSAGE,
            0,
        },
        REGS_REGSANDMEM,
        0,
        PRB_MAYBE_FIELD_NAME("regs")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
};

// 'KGsp' field defaults

// 'KGsp' field descriptors
const PRB_FIELD_DESC prb_fields_nvdebug_eng_kgsp[] = {
    {
        1,
        {
            PRB_REPEATED,
            PRB_MESSAGE,
            0,
        },
        NVDEBUG_ENG_KGSP_RPCINFO,
        0,
        PRB_MAYBE_FIELD_NAME("rpc_history")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        2,
        {
            PRB_REPEATED,
            PRB_MESSAGE,
            0,
        },
        NVDEBUG_ENG_KGSP_RPCINFO,
        0,
        PRB_MAYBE_FIELD_NAME("event_history")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
};

// 'RmData' field defaults

// 'RmData' field descriptors
const PRB_FIELD_DESC prb_fields_nvdebug_eng_mc_rmdata[] = {
    {
        1,
        {
            PRB_OPTIONAL,
            PRB_UINT32,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("pmcBoot0")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
};

// 'PciBarInfo' field defaults

// 'PciBarInfo' field descriptors
const PRB_FIELD_DESC prb_fields_nvdebug_eng_mc_pcibarinfo[] = {
    {
        1,
        {
            PRB_OPTIONAL,
            PRB_UINT64,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("offset")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        2,
        {
            PRB_OPTIONAL,
            PRB_UINT64,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("length")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
};

// 'RpcInfo' field defaults

// 'RpcInfo' field descriptors
const PRB_FIELD_DESC prb_fields_nvdebug_eng_kgsp_rpcinfo[] = {
    {
        1,
        {
            PRB_REQUIRED,
            PRB_UINT32,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("function")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        2,
        {
            PRB_REQUIRED,
            PRB_UINT64,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("ts_start")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        3,
        {
            PRB_REQUIRED,
            PRB_UINT64,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("ts_end")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        4,
        {
            PRB_OPTIONAL,
            PRB_UINT32,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("data0")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
    {
        5,
        {
            PRB_OPTIONAL,
            PRB_UINT32,
            0,
        },
        0,
        0,
        PRB_MAYBE_FIELD_NAME("data1")
        PRB_MAYBE_FIELD_DEFAULT(0)
    },
};

// Message descriptors
const PRB_MSG_DESC prb_messages_nvdebug_eng[] = {
    {
        3,
        prb_fields_nvdebug_eng_mc,
        PRB_MAYBE_MESSAGE_NAME("NvDebug.Eng.Mc")
    },
    {
        13,
        prb_fields_nvdebug_eng_gpu,
        PRB_MAYBE_MESSAGE_NAME("NvDebug.Eng.Gpu")
    },
    {
        1,
        prb_fields_nvdebug_eng_nvd,
        PRB_MAYBE_MESSAGE_NAME("NvDebug.Eng.Nvd")
    },
    {
        2,
        prb_fields_nvdebug_eng_kgsp,
        PRB_MAYBE_MESSAGE_NAME("NvDebug.Eng.KGsp")
    },
    {
        1,
        prb_fields_nvdebug_eng_mc_rmdata,
        PRB_MAYBE_MESSAGE_NAME("NvDebug.Eng.Mc.RmData")
    },
    {
        2,
        prb_fields_nvdebug_eng_mc_pcibarinfo,
        PRB_MAYBE_MESSAGE_NAME("NvDebug.Eng.Mc.PciBarInfo")
    },
    {
        5,
        prb_fields_nvdebug_eng_kgsp_rpcinfo,
        PRB_MAYBE_MESSAGE_NAME("NvDebug.Eng.KGsp.RpcInfo")
    },
};

// Service descriptors
const PRB_SERVICE_DESC prb_services_nvdebug_eng[] = {
   { 0 }
};

