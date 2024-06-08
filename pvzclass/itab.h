#pragma once

#include "./PVZ.h"

namespace PfxBits {
	constexpr DWORD none  = 0x00000000;
	constexpr DWORD inv64 = 0x00000001;
	constexpr DWORD def64 = 0x00000002;
	constexpr DWORD oso   = 0x00000004;
	constexpr DWORD aso   = 0x00000008;
	constexpr DWORD rexb  = 0x00000010;
	constexpr DWORD rexw  = 0x00000020;
	constexpr DWORD rexr  = 0x00000040;
	constexpr DWORD rexx  = 0x00000080;
	constexpr DWORD seg   = 0x00000100;
	constexpr DWORD vexl  = 0x00000200;
	constexpr DWORD vexw  = 0x00000400;
	constexpr DWORD str   = 0x00000800;
	constexpr DWORD strz  = 0x00001000;
	
	static inline bool INV64(DWORD n) {return (n & inv64) != 0;}
	static inline bool DEF64(DWORD n) {return (n & def64) != 0;}
	static inline bool OSO  (DWORD n) {return (n & oso  ) != 0;}
	static inline bool ASO  (DWORD n) {return (n & aso  ) != 0;}
	static inline bool REXB (DWORD n) {return (n & rexb ) != 0;}
	static inline bool REXW (DWORD n) {return (n & rexw ) != 0;}
	static inline bool REXR (DWORD n) {return (n & rexr ) != 0;}
	static inline bool REXX (DWORD n) {return (n & rexx ) != 0;}
	static inline bool SEG  (DWORD n) {return (n & seg  ) != 0;}
	static inline bool VEXL (DWORD n) {return (n & vexl ) != 0;}
	static inline bool VEXW (DWORD n) {return (n & vexw ) != 0;}
	static inline bool STR  (DWORD n) {return (n & str  ) != 0;}
	static inline bool STRZ (DWORD n) {return (n & strz ) != 0;}
}

enum RegisterType {
    R_REGISTER_BEGIN = -1,
    R_NONE,
    // 8位通用寄存器
    R_AL, R_CL, R_DL, R_BL,
    R_AH, R_CH, R_DH, R_BH,
    R_SPL, R_BPL, R_SIL, R_DIL,
    R_R8B, R_R9B, R_R10B, R_R11B,
    R_R12B, R_R13B, R_R14B, R_R15B,

    // 16位通用寄存器
    R_AX, R_CX, R_DX, R_BX,
    R_SP, R_BP, R_SI, R_DI,
    R_R8W, R_R9W, R_R10W, R_R11W,
    R_R12W, R_R13W, R_R14W, R_R15W,

    // 32位通用寄存器
    R_EAX, R_ECX, R_EDX, R_EBX,
    R_ESP, R_EBP, R_ESI, R_EDI,
    R_R8D, R_R9D, R_R10D, R_R11D,
    R_R12D, R_R13D, R_R14D, R_R15D,

    // 64位通用寄存器
    R_RAX, R_RCX, R_RDX, R_RBX,
    R_RSP, R_RBP, R_RSI, R_RDI,
    R_R8, R_R9, R_R10, R_R11,
    R_R12, R_R13, R_R14, R_R15,

    // 段寄存器
    R_ES, R_CS, R_SS, R_DS,
    R_FS, R_GS,

    // 控制寄存器
    R_CR0, R_CR1, R_CR2, R_CR3,
    R_CR4, R_CR5, R_CR6, R_CR7,
    R_CR8, R_CR9, R_CR10, R_CR11,
    R_CR12, R_CR13, R_CR14, R_CR15,

    // 调试寄存器
    R_DR0, R_DR1, R_DR2, R_DR3,
    R_DR4, R_DR5, R_DR6, R_DR7,
    R_DR8, R_DR9, R_DR10, R_DR11,
    R_DR12, R_DR13, R_DR14, R_DR15,

    // MMX寄存器
    R_MM0, R_MM1, R_MM2, R_MM3,
    R_MM4, R_MM5, R_MM6, R_MM7,

    // x87寄存器
    R_ST0, R_ST1, R_ST2, R_ST3,
    R_ST4, R_ST5, R_ST6, R_ST7,

    // 拓展多媒体寄存器
    R_XMM0, R_XMM1, R_XMM2, R_XMM3,
    R_XMM4, R_XMM5, R_XMM6, R_XMM7,
    R_XMM8, R_XMM9, R_XMM10, R_XMM11,
    R_XMM12, R_XMM13, R_XMM14, R_XMM15,

    // 256B 多媒体寄存器
    R_YMM0, R_YMM1, R_YMM2, R_YMM3,
    R_YMM4, R_YMM5, R_YMM6, R_YMM7,
    R_YMM8, R_YMM9, R_YMM10, R_YMM11,
    R_YMM12, R_YMM13, R_YMM14, R_YMM15,

    // 程序计数器
    R_RIP,
    R_MAX_REGISTER = 155
};

enum OperandType {
    O_TYPE_BEGIN = -1,
    O_NONE,
    O_REG, 
    O_MEM,
    O_PTR,
    O_IMM,
    O_JIMM,
    O_CONST,
    O_MAX_OPERAND_TYPE = 7
};

// 指令表类型
enum class ITabType {
    MOD,
    X87,
    TABLE,
    ASIZE,
    OSIZE,
    VEX,
    MODE,
    VEX_L,
    VENDOR,
    REG,
    RM,
    SSE,
    _3DNOW,
    VEX_W
};

// 助记符 
enum MnemonicCode {
    MC_AAA,
    MC_AAD,
    MC_AAM,
    MC_AAS,
    MC_ADC,
    MC_ADD,
    MC_ADDPD,
    MC_ADDPS,
    MC_ADDSD,
    MC_ADDSS,
    MC_ADDSUBPD,
    MC_ADDSUBPS,
    MC_AESDEC,
    MC_AESDECLAST,
    MC_AESENC,
    MC_AESENCLAST,
    MC_AESIMC,
    MC_AESKEYGENASSIST,
    MC_AND,
    MC_ANDNPD,
    MC_ANDNPS,
    MC_ANDPD,
    MC_ANDPS,
    MC_ARPL,
    MC_BLENDPD,
    MC_BLENDPS,
    MC_BLENDVPD,
    MC_BLENDVPS,
    MC_BOUND,
    MC_BSF,
    MC_BSR,
    MC_BSWAP,
    MC_BT,
    MC_BTC,
    MC_BTR,
    MC_BTS,
    MC_CALL,
    MC_CBW,
    MC_CDQ,
    MC_CDQE,
    MC_CLC,
    MC_CLD,
    MC_CLFLUSH,
    MC_CLGI,
    MC_CLI,
    MC_CLTS,
    MC_CMC,
    MC_CMOVA,
    MC_CMOVAE,
    MC_CMOVB,
    MC_CMOVBE,
    MC_CMOVG,
    MC_CMOVGE,
    MC_CMOVL,
    MC_CMOVLE,
    MC_CMOVNO,
    MC_CMOVNP,
    MC_CMOVNS,
    MC_CMOVNZ,
    MC_CMOVO,
    MC_CMOVP,
    MC_CMOVS,
    MC_CMOVZ,
    MC_CMP,
    MC_CMPPD,
    MC_CMPPS,
    MC_CMPSB,
    MC_CMPSD,
    MC_CMPSQ,
    MC_CMPSS,
    MC_CMPSW,
    MC_CMPXCHG,
    MC_CMPXCHG16B,
    MC_CMPXCHG8B,
    MC_COMISD,
    MC_COMISS,
    MC_CPUID,
    MC_CQO,
    MC_CRC32,
    MC_CVTDQ2PD,
    MC_CVTDQ2PS,
    MC_CVTPD2DQ,
    MC_CVTPD2PI,
    MC_CVTPD2PS,
    MC_CVTPI2PD,
    MC_CVTPI2PS,
    MC_CVTPS2DQ,
    MC_CVTPS2PD,
    MC_CVTPS2PI,
    MC_CVTSD2SI,
    MC_CVTSD2SS,
    MC_CVTSI2SD,
    MC_CVTSI2SS,
    MC_CVTSS2SD,
    MC_CVTSS2SI,
    MC_CVTTPD2DQ,
    MC_CVTTPD2PI,
    MC_CVTTPS2DQ,
    MC_CVTTPS2PI,
    MC_CVTTSD2SI,
    MC_CVTTSS2SI,
    MC_CWD,
    MC_CWDE,
    MC_DAA,
    MC_DAS,
    MC_DEC,
    MC_DIV,
    MC_DIVPD,
    MC_DIVPS,
    MC_DIVSD,
    MC_DIVSS,
    MC_DPPD,
    MC_DPPS,
    MC_EMMS,
    MC_ENTER,
    MC_EXTRACTPS,
    MC_F2XM1,
    MC_FABS,
    MC_FADD,
    MC_FADDP,
    MC_FBLD,
    MC_FBSTP,
    MC_FCHS,
    MC_FCLEX,
    MC_FCMOVB,
    MC_FCMOVBE,
    MC_FCMOVE,
    MC_FCMOVNB,
    MC_FCMOVNBE,
    MC_FCMOVNE,
    MC_FCMOVNU,
    MC_FCMOVU,
    MC_FCOM,
    MC_FCOM2,
    MC_FCOMI,
    MC_FCOMIP,
    MC_FCOMP,
    MC_FCOMP3,
    MC_FCOMP5,
    MC_FCOMPP,
    MC_FCOS,
    MC_FDECSTP,
    MC_FDIV,
    MC_FDIVP,
    MC_FDIVR,
    MC_FDIVRP,
    MC_FEMMS,
    MC_FFREE,
    MC_FFREEP,
    MC_FIADD,
    MC_FICOM,
    MC_FICOMP,
    MC_FIDIV,
    MC_FIDIVR,
    MC_FILD,
    MC_FIMUL,
    MC_FINCSTP,
    MC_FIST,
    MC_FISTP,
    MC_FISTTP,
    MC_FISUB,
    MC_FISUBR,
    MC_FLD,
    MC_FLD1,
    MC_FLDCW,
    MC_FLDENV,
    MC_FLDL2E,
    MC_FLDL2T,
    MC_FLDLG2,
    MC_FLDLN2,
    MC_FLDPI,
    MC_FLDZ,
    MC_FMUL,
    MC_FMULP,
    MC_FNDISI,
    MC_FNENI,
    MC_FNINIT,
    MC_FNOP,
    MC_FNSAVE,
    MC_FNSETPM,
    MC_FNSTCW,
    MC_FNSTENV,
    MC_FNSTSW,
    MC_FPATAN,
    MC_FPREM,
    MC_FPREM1,
    MC_FPTAN,
    MC_FRNDINT,
    MC_FRSTOR,
    MC_FRSTPM,
    MC_FSCALE,
    MC_FSIN,
    MC_FSINCOS,
    MC_FSQRT,
    MC_FST,
    MC_FSTP,
    MC_FSTP1,
    MC_FSTP8,
    MC_FSTP9,
    MC_FSUB,
    MC_FSUBP,
    MC_FSUBR,
    MC_FSUBRP,
    MC_FTST,
    MC_FUCOM,
    MC_FUCOMI,
    MC_FUCOMIP,
    MC_FUCOMP,
    MC_FUCOMPP,
    MC_FXAM,
    MC_FXCH,
    MC_FXCH4,
    MC_FXCH7,
    MC_FXRSTOR,
    MC_FXSAVE,
    MC_FXTRACT,
    MC_FYL2X,
    MC_FYL2XP1,
    MC_GETSEC,
    MC_HADDPD,
    MC_HADDPS,
    MC_HLT,
    MC_HSUBPD,
    MC_HSUBPS,
    MC_IDIV,
    MC_IMUL,
    MC_IN,
    MC_INC,
    MC_INSB,
    MC_INSD,
    MC_INSERTPS,
    MC_INSW,
    MC_INT,
    MC_INT1,
    MC_INT3,
    MC_INTO,
    MC_INVD,
    MC_INVEPT,
    MC_INVLPG,
    MC_INVLPGA,
    MC_INVVPID,
    MC_IRETD,
    MC_IRETQ,
    MC_IRETW,
    MC_JA,
    MC_JAE,
    MC_JB,
    MC_JBE,
    MC_JCXZ,
    MC_JECXZ,
    MC_JG,
    MC_JGE,
    MC_JL,
    MC_JLE,
    MC_JMP,
    MC_JNO,
    MC_JNP,
    MC_JNS,
    MC_JNZ,
    MC_JO,
    MC_JP,
    MC_JRCXZ,
    MC_JS,
    MC_JZ,
    MC_LAHF,
    MC_LAR,
    MC_LDDQU,
    MC_LDMXCSR,
    MC_LDS,
    MC_LEA,
    MC_LEAVE,
    MC_LES,
    MC_LFENCE,
    MC_LFS,
    MC_LGDT,
    MC_LGS,
    MC_LIDT,
    MC_LLDT,
    MC_LMSW,
    MC_LOCK,
    MC_LODSB,
    MC_LODSD,
    MC_LODSQ,
    MC_LODSW,
    MC_LOOP,
    MC_LOOPE,
    MC_LOOPNE,
    MC_LSL,
    MC_LSS,
    MC_LTR,
    MC_MASKMOVDQU,
    MC_MASKMOVQ,
    MC_MAXPD,
    MC_MAXPS,
    MC_MAXSD,
    MC_MAXSS,
    MC_MFENCE,
    MC_MINPD,
    MC_MINPS,
    MC_MINSD,
    MC_MINSS,
    MC_MONITOR,
    MC_MONTMUL,
    MC_MOV,
    MC_MOVAPD,
    MC_MOVAPS,
    MC_MOVBE,
    MC_MOVD,
    MC_MOVDDUP,
    MC_MOVDQ2Q,
    MC_MOVDQA,
    MC_MOVDQU,
    MC_MOVHLPS,
    MC_MOVHPD,
    MC_MOVHPS,
    MC_MOVLHPS,
    MC_MOVLPD,
    MC_MOVLPS,
    MC_MOVMSKPD,
    MC_MOVMSKPS,
    MC_MOVNTDQ,
    MC_MOVNTDQA,
    MC_MOVNTI,
    MC_MOVNTPD,
    MC_MOVNTPS,
    MC_MOVNTQ,
    MC_MOVQ,
    MC_MOVQ2DQ,
    MC_MOVSB,
    MC_MOVSD,
    MC_MOVSHDUP,
    MC_MOVSLDUP,
    MC_MOVSQ,
    MC_MOVSS,
    MC_MOVSW,
    MC_MOVSX,
    MC_MOVSXD,
    MC_MOVUPD,
    MC_MOVUPS,
    MC_MOVZX,
    MC_MPSADBW,
    MC_MUL,
    MC_MULPD,
    MC_MULPS,
    MC_MULSD,
    MC_MULSS,
    MC_MWAIT,
    MC_NEG,
    MC_NOP,
    MC_NOT,
    MC_OR,
    MC_ORPD,
    MC_ORPS,
    MC_OUT,
    MC_OUTSB,
    MC_OUTSD,
    MC_OUTSW,
    MC_PABSB,
    MC_PABSD,
    MC_PABSW,
    MC_PACKSSDW,
    MC_PACKSSWB,
    MC_PACKUSDW,
    MC_PACKUSWB,
    MC_PADDB,
    MC_PADDD,
    MC_PADDQ,
    MC_PADDSB,
    MC_PADDSW,
    MC_PADDUSB,
    MC_PADDUSW,
    MC_PADDW,
    MC_PALIGNR,
    MC_PAND,
    MC_PANDN,
    MC_PAVGB,
    MC_PAVGUSB,
    MC_PAVGW,
    MC_PBLENDVB,
    MC_PBLENDW,
    MC_PCLMULQDQ,
    MC_PCMPEQB,
    MC_PCMPEQD,
    MC_PCMPEQQ,
    MC_PCMPEQW,
    MC_PCMPESTRI,
    MC_PCMPESTRM,
    MC_PCMPGTB,
    MC_PCMPGTD,
    MC_PCMPGTQ,
    MC_PCMPGTW,
    MC_PCMPISTRI,
    MC_PCMPISTRM,
    MC_PEXTRB,
    MC_PEXTRD,
    MC_PEXTRQ,
    MC_PEXTRW,
    MC_PF2ID,
    MC_PF2IW,
    MC_PFACC,
    MC_PFADD,
    MC_PFCMPEQ,
    MC_PFCMPGE,
    MC_PFCMPGT,
    MC_PFMAX,
    MC_PFMIN,
    MC_PFMUL,
    MC_PFNACC,
    MC_PFPNACC,
    MC_PFRCP,
    MC_PFRCPIT1,
    MC_PFRCPIT2,
    MC_PFRSQIT1,
    MC_PFRSQRT,
    MC_PFSUB,
    MC_PFSUBR,
    MC_PHADDD,
    MC_PHADDSW,
    MC_PHADDW,
    MC_PHMINPOSUW,
    MC_PHSUBD,
    MC_PHSUBSW,
    MC_PHSUBW,
    MC_PI2FD,
    MC_PI2FW,
    MC_PINSRB,
    MC_PINSRD,
    MC_PINSRQ,
    MC_PINSRW,
    MC_PMADDUBSW,
    MC_PMADDWD,
    MC_PMAXSB,
    MC_PMAXSD,
    MC_PMAXSW,
    MC_PMAXUB,
    MC_PMAXUD,
    MC_PMAXUW,
    MC_PMINSB,
    MC_PMINSD,
    MC_PMINSW,
    MC_PMINUB,
    MC_PMINUD,
    MC_PMINUW,
    MC_PMOVMSKB,
    MC_PMOVSXBD,
    MC_PMOVSXBQ,
    MC_PMOVSXBW,
    MC_PMOVSXDQ,
    MC_PMOVSXWD,
    MC_PMOVSXWQ,
    MC_PMOVZXBD,
    MC_PMOVZXBQ,
    MC_PMOVZXBW,
    MC_PMOVZXDQ,
    MC_PMOVZXWD,
    MC_PMOVZXWQ,
    MC_PMULDQ,
    MC_PMULHRSW,
    MC_PMULHRW,
    MC_PMULHUW,
    MC_PMULHW,
    MC_PMULLD,
    MC_PMULLW,
    MC_PMULUDQ,
    MC_POP,
    MC_POPA,
    MC_POPAD,
    MC_POPCNT,
    MC_POPFD,
    MC_POPFQ,
    MC_POPFW,
    MC_POR,
    MC_PREFETCH,
    MC_PREFETCHNTA,
    MC_PREFETCHT0,
    MC_PREFETCHT1,
    MC_PREFETCHT2,
    MC_PSADBW,
    MC_PSHUFB,
    MC_PSHUFD,
    MC_PSHUFHW,
    MC_PSHUFLW,
    MC_PSHUFW,
    MC_PSIGNB,
    MC_PSIGND,
    MC_PSIGNW,
    MC_PSLLD,
    MC_PSLLDQ,
    MC_PSLLQ,
    MC_PSLLW,
    MC_PSRAD,
    MC_PSRAW,
    MC_PSRLD,
    MC_PSRLDQ,
    MC_PSRLQ,
    MC_PSRLW,
    MC_PSUBB,
    MC_PSUBD,
    MC_PSUBQ,
    MC_PSUBSB,
    MC_PSUBSW,
    MC_PSUBUSB,
    MC_PSUBUSW,
    MC_PSUBW,
    MC_PSWAPD,
    MC_PTEST,
    MC_PUNPCKHBW,
    MC_PUNPCKHDQ,
    MC_PUNPCKHQDQ,
    MC_PUNPCKHWD,
    MC_PUNPCKLBW,
    MC_PUNPCKLDQ,
    MC_PUNPCKLQDQ,
    MC_PUNPCKLWD,
    MC_PUSH,
    MC_PUSHA,
    MC_PUSHAD,
    MC_PUSHFD,
    MC_PUSHFQ,
    MC_PUSHFW,
    MC_PXOR,
    MC_RCL,
    MC_RCPPS,
    MC_RCPSS,
    MC_RCR,
    MC_RDMSR,
    MC_RDPMC,
    MC_RDRAND,
    MC_RDTSC,
    MC_RDTSCP,
    MC_REP,
    MC_REPNE,
    MC_RET,
    MC_RETF,
    MC_ROL,
    MC_ROR,
    MC_ROUNDPD,
    MC_ROUNDPS,
    MC_ROUNDSD,
    MC_ROUNDSS,
    MC_RSM,
    MC_RSQRTPS,
    MC_RSQRTSS,
    MC_SAHF,
    MC_SALC,
    MC_SAR,
    MC_SBB,
    MC_SCASB,
    MC_SCASD,
    MC_SCASQ,
    MC_SCASW,
    MC_SETA,
    MC_SETAE,
    MC_SETB,
    MC_SETBE,
    MC_SETG,
    MC_SETGE,
    MC_SETL,
    MC_SETLE,
    MC_SETNO,
    MC_SETNP,
    MC_SETNS,
    MC_SETNZ,
    MC_SETO,
    MC_SETP,
    MC_SETS,
    MC_SETZ,
    MC_SFENCE,
    MC_SGDT,
    MC_SHL,
    MC_SHLD,
    MC_SHR,
    MC_SHRD,
    MC_SHUFPD,
    MC_SHUFPS,
    MC_SIDT,
    MC_SKINIT,
    MC_SLDT,
    MC_SMSW,
    MC_SQRTPD,
    MC_SQRTPS,
    MC_SQRTSD,
    MC_SQRTSS,
    MC_STC,
    MC_STD,
    MC_STGI,
    MC_STI,
    MC_STMXCSR,
    MC_STOSB,
    MC_STOSD,
    MC_STOSQ,
    MC_STOSW,
    MC_STR,
    MC_SUB,
    MC_SUBPD,
    MC_SUBPS,
    MC_SUBSD,
    MC_SUBSS,
    MC_SWAPGS,
    MC_SYSCALL,
    MC_SYSENTER,
    MC_SYSEXIT,
    MC_SYSRET,
    MC_TEST,
    MC_UCOMISD,
    MC_UCOMISS,
    MC_UD2,
    MC_UNPCKHPD,
    MC_UNPCKHPS,
    MC_UNPCKLPD,
    MC_UNPCKLPS,
    MC_VADDPD,
    MC_VADDPS,
    MC_VADDSD,
    MC_VADDSS,
    MC_VADDSUBPD,
    MC_VADDSUBPS,
    MC_VAESDEC,
    MC_VAESDECLAST,
    MC_VAESENC,
    MC_VAESENCLAST,
    MC_VAESIMC,
    MC_VAESKEYGENASSIST,
    MC_VANDNPD,
    MC_VANDNPS,
    MC_VANDPD,
    MC_VANDPS,
    MC_VBLENDPD,
    MC_VBLENDPS,
    MC_VBLENDVPD,
    MC_VBLENDVPS,
    MC_VBROADCASTSD,
    MC_VBROADCASTSS,
    MC_VCMPPD,
    MC_VCMPPS,
    MC_VCMPSD,
    MC_VCMPSS,
    MC_VCOMISD,
    MC_VCOMISS,
    MC_VCVTDQ2PD,
    MC_VCVTDQ2PS,
    MC_VCVTPD2DQ,
    MC_VCVTPD2PS,
    MC_VCVTPS2DQ,
    MC_VCVTPS2PD,
    MC_VCVTSD2SI,
    MC_VCVTSD2SS,
    MC_VCVTSI2SD,
    MC_VCVTSI2SS,
    MC_VCVTSS2SD,
    MC_VCVTSS2SI,
    MC_VCVTTPD2DQ,
    MC_VCVTTPS2DQ,
    MC_VCVTTSD2SI,
    MC_VCVTTSS2SI,
    MC_VDIVPD,
    MC_VDIVPS,
    MC_VDIVSD,
    MC_VDIVSS,
    MC_VDPPD,
    MC_VDPPS,
    MC_VERR,
    MC_VERW,
    MC_VEXTRACTF128,
    MC_VEXTRACTPS,
    MC_VHADDPD,
    MC_VHADDPS,
    MC_VHSUBPD,
    MC_VHSUBPS,
    MC_VINSERTF128,
    MC_VINSERTPS,
    MC_VLDDQU,
    MC_VMASKMOVDQU,
    MC_VMASKMOVPD,
    MC_VMASKMOVPS,
    MC_VMAXPD,
    MC_VMAXPS,
    MC_VMAXSD,
    MC_VMAXSS,
    MC_VMCALL,
    MC_VMCLEAR,
    MC_VMINPD,
    MC_VMINPS,
    MC_VMINSD,
    MC_VMINSS,
    MC_VMLAUNCH,
    MC_VMLOAD,
    MC_VMMCALL,
    MC_VMOVAPD,
    MC_VMOVAPS,
    MC_VMOVD,
    MC_VMOVDDUP,
    MC_VMOVDQA,
    MC_VMOVDQU,
    MC_VMOVHLPS,
    MC_VMOVHPD,
    MC_VMOVHPS,
    MC_VMOVLHPS,
    MC_VMOVLPD,
    MC_VMOVLPS,
    MC_VMOVMSKPD,
    MC_VMOVMSKPS,
    MC_VMOVNTDQ,
    MC_VMOVNTDQA,
    MC_VMOVNTPD,
    MC_VMOVNTPS,
    MC_VMOVQ,
    MC_VMOVSD,
    MC_VMOVSHDUP,
    MC_VMOVSLDUP,
    MC_VMOVSS,
    MC_VMOVUPD,
    MC_VMOVUPS,
    MC_VMPSADBW,
    MC_VMPTRLD,
    MC_VMPTRST,
    MC_VMREAD,
    MC_VMRESUME,
    MC_VMRUN,
    MC_VMSAVE,
    MC_VMULPD,
    MC_VMULPS,
    MC_VMULSD,
    MC_VMULSS,
    MC_VMWRITE,
    MC_VMXOFF,
    MC_VMXON,
    MC_VORPD,
    MC_VORPS,
    MC_VPABSB,
    MC_VPABSD,
    MC_VPABSW,
    MC_VPACKSSDW,
    MC_VPACKSSWB,
    MC_VPACKUSDW,
    MC_VPACKUSWB,
    MC_VPADDB,
    MC_VPADDD,
    MC_VPADDQ,
    MC_VPADDSB,
    MC_VPADDSW,
    MC_VPADDUSB,
    MC_VPADDUSW,
    MC_VPADDW,
    MC_VPALIGNR,
    MC_VPAND,
    MC_VPANDN,
    MC_VPAVGB,
    MC_VPAVGW,
    MC_VPBLENDVB,
    MC_VPBLENDW,
    MC_VPCLMULQDQ,
    MC_VPCMPEQB,
    MC_VPCMPEQD,
    MC_VPCMPEQQ,
    MC_VPCMPEQW,
    MC_VPCMPESTRI,
    MC_VPCMPESTRM,
    MC_VPCMPGTB,
    MC_VPCMPGTD,
    MC_VPCMPGTQ,
    MC_VPCMPGTW,
    MC_VPCMPISTRI,
    MC_VPCMPISTRM,
    MC_VPERM2F128,
    MC_VPERMILPD,
    MC_VPERMILPS,
    MC_VPEXTRB,
    MC_VPEXTRD,
    MC_VPEXTRQ,
    MC_VPEXTRW,
    MC_VPHADDD,
    MC_VPHADDSW,
    MC_VPHADDW,
    MC_VPHMINPOSUW,
    MC_VPHSUBD,
    MC_VPHSUBSW,
    MC_VPHSUBW,
    MC_VPINSRB,
    MC_VPINSRD,
    MC_VPINSRQ,
    MC_VPINSRW,
    MC_VPMADDUBSW,
    MC_VPMADDWD,
    MC_VPMAXSB,
    MC_VPMAXSD,
    MC_VPMAXSW,
    MC_VPMAXUB,
    MC_VPMAXUD,
    MC_VPMAXUW,
    MC_VPMINSB,
    MC_VPMINSD,
    MC_VPMINSW,
    MC_VPMINUB,
    MC_VPMINUD,
    MC_VPMINUW,
    MC_VPMOVMSKB,
    MC_VPMOVSXBD,
    MC_VPMOVSXBQ,
    MC_VPMOVSXBW,
    MC_VPMOVSXWD,
    MC_VPMOVSXWQ,
    MC_VPMOVZXBD,
    MC_VPMOVZXBQ,
    MC_VPMOVZXBW,
    MC_VPMOVZXDQ,
    MC_VPMOVZXWD,
    MC_VPMOVZXWQ,
    MC_VPMULDQ,
    MC_VPMULHRSW,
    MC_VPMULHUW,
    MC_VPMULHW,
    MC_VPMULLD,
    MC_VPMULLW,
    MC_VPOR,
    MC_VPSADBW,
    MC_VPSHUFB,
    MC_VPSHUFD,
    MC_VPSHUFHW,
    MC_VPSHUFLW,
    MC_VPSIGNB,
    MC_VPSIGND,
    MC_VPSIGNW,
    MC_VPSLLD,
    MC_VPSLLDQ,
    MC_VPSLLQ,
    MC_VPSLLW,
    MC_VPSRAD,
    MC_VPSRAW,
    MC_VPSRLD,
    MC_VPSRLDQ,
    MC_VPSRLQ,
    MC_VPSRLW,
    MC_VPSUBB,
    MC_VPSUBD,
    MC_VPSUBQ,
    MC_VPSUBSB,
    MC_VPSUBSW,
    MC_VPSUBUSB,
    MC_VPSUBUSW,
    MC_VPSUBW,
    MC_VPTEST,
    MC_VPUNPCKHBW,
    MC_VPUNPCKHDQ,
    MC_VPUNPCKHQDQ,
    MC_VPUNPCKHWD,
    MC_VPUNPCKLBW,
    MC_VPUNPCKLDQ,
    MC_VPUNPCKLQDQ,
    MC_VPUNPCKLWD,
    MC_VPXOR,
    MC_VRCPPS,
    MC_VRCPSS,
    MC_VROUNDPD,
    MC_VROUNDPS,
    MC_VROUNDSD,
    MC_VROUNDSS,
    MC_VRSQRTPS,
    MC_VRSQRTSS,
    MC_VSHUFPD,
    MC_VSHUFPS,
    MC_VSQRTPD,
    MC_VSQRTPS,
    MC_VSQRTSD,
    MC_VSQRTSS,
    MC_VSTMXCSR,
    MC_VSUBPD,
    MC_VSUBPS,
    MC_VSUBSD,
    MC_VSUBSS,
    MC_VTESTPD,
    MC_VTESTPS,
    MC_VUCOMISD,
    MC_VUCOMISS,
    MC_VUNPCKHPD,
    MC_VUNPCKHPS,
    MC_VUNPCKLPD,
    MC_VUNPCKLPS,
    MC_VXORPD,
    MC_VXORPS,
    MC_VZEROALL,
    MC_VZEROUPPER,
    MC_WAIT,
    MC_WBINVD,
    MC_WRMSR,
    MC_XADD,
    MC_XCHG,
    MC_XCRYPTCBC,
    MC_XCRYPTCFB,
    MC_XCRYPTCTR,
    MC_XCRYPTECB,
    MC_XCRYPTOFB,
    MC_XGETBV,
    MC_XLATB,
    MC_XOR,
    MC_XORPD,
    MC_XORPS,
    MC_XRSTOR,
    MC_XSAVE,
    MC_XSETBV,
    MC_XSHA1,
    MC_XSHA256,
    MC_XSTORE,
    MC_INVALID,
    MC_3DNOW,
    MC_NONE,
    MC_DB,
    MC_PAUSE
};


// 查询表表项 
struct LookupTableEntry {
    const WORD *table;
    ITabType type;
    const char *classification;
};

// 操作数类型
enum class OperandCode {
    NONE,
    A, E, M, G,
    I, F,
    R0, R1, R2, R3,
    R4, R5, R6, R7,
    AL, CL, DL,
    AX, CX, DX,
    eAX, eCX, eDX, rAX, rCX, rDX,
    ES, CS, SS, DS, FS, GS,
    ST0, ST1, ST2, ST3,
    ST4, ST5, ST6, ST7,
    J, S, O,          
    I1, I3, sI,
    V, W, Q, P, 
    U, N, MU, H,
    L,
    R, C, D,       
    MR
};

// 操作数大小(位)
namespace OperandSize {
	constexpr WORD NA  = 0;
	constexpr WORD Z   = 1;
	constexpr WORD V   = 2;
	constexpr WORD Y   = 3;
	constexpr WORD X   = 4;
	constexpr WORD RDQ = 7;
	constexpr WORD B   = 8;
	constexpr WORD W   = 16;
	constexpr WORD D   = 32;
    constexpr WORD A   = 48;
	constexpr WORD Q   = 64;
	constexpr WORD T   = 80;
	constexpr WORD O   = 12;
	constexpr WORD DQ  = 128;
	constexpr WORD QQ  = 256;
    // 复合型 
    constexpr WORD BD  = (((B << 8) & 0xFF00) | (D & 0x00FF));
    constexpr WORD BV  = (((B << 8) & 0xFF00) | (V & 0x00FF));
    constexpr WORD WD  = (((W << 8) & 0xFF00) | (D & 0x00FF));
    constexpr WORD WV  = (((W << 8) & 0xFF00) | (V & 0x00FF));
    constexpr WORD WY  = (((W << 8) & 0xFF00) | (Y & 0x00FF));
    constexpr WORD DY  = (((D << 8) & 0xFF00) | (Y & 0x00FF));
    constexpr WORD WO  = (((W << 8) & 0xFF00) | (O & 0x00FF));
    constexpr WORD DO  = (((D << 8) & 0xFF00) | (O & 0x00FF));
    constexpr WORD QO  = (((Q << 8) & 0xFF00) | (O & 0x00FF));
};

struct OperandDefinition {
	OperandCode code;
	WORD size;
};

struct InstructionDefinition {
	MnemonicCode mnemonic;
	OperandDefinition operand1;
	OperandDefinition operand2;
	OperandDefinition operand3;
	OperandDefinition operand4;
	DWORD prefix;
};

extern LookupTableEntry LookupTable[];
extern InstructionDefinition InstructionTable[];
extern const char *Mnemonics[];

inline static WORD MxMemSize(WORD size) { return (size >> 8) & 0xFF; }
inline static WORD MxRegSize(WORD size) { return size & 0xFF;}