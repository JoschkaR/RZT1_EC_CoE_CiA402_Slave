MEMORY
{
	ATCM : ORIGIN = 0x0, LENGTH = 524288
	BTCM : ORIGIN = 0x800000, LENGTH = 32768
	INST_RAM : ORIGIN = 0x4000000, LENGTH = 524288
	SPIBSC : ORIGIN = 0x10000000, LENGTH = 67108864
	DATA_RAM : ORIGIN = 0x20000000, LENGTH = 524288
	DATA_RAM_MIRROR : ORIGIN = 0x22000000, LENGTH = 524288
	INST_RAM_MIRROR : ORIGIN = 0x24000000, LENGTH = 524288
	SPIBSC_MIRROR : ORIGIN = 0x30000000, LENGTH = 67108864
	CSx_MIRROR : ORIGIN = 0x40000000, LENGTH = 402653184
	CSx : ORIGIN = 0x60000000, LENGTH = 402653184
}

SECTIONS
{
	.loader_param 0x30000000 : AT (0x30000000)
	{
		KEEP(*(.loader_param))
	} > SPIBSC_MIRROR
	.flash_contents 0x3000004C : AT (0x3000004C)
	{
		_mloader_text = .;
		. = . + (_loader_text_end - _loader_text_start);
		_mfvector = .;
		. = . +(_fvector_end - _fvector_start);
		_mtext = .;
		. = . + (_text_end - _text_start);
		_mdata = .;
		. = . + (_data_end - _data_start);
		flash_contents_end = .;
	} > SPIBSC_MIRROR
	.loader_text 0x802000 : AT (_mloader_text)
	{
		_loader_text_start = .;
		*(.loader_text)
	} > BTCM
	.loader_text2 : 
	{
		*(.loader_text2)
	} > BTCM
	.loader_data : 
	{
		./src/common/*.o(.data);
		__loader_bss_start = .;
		./src/common/*.o(.bss);
		./src/common/*.o(COMMON);
        __loader_bss_end = . ;
		. = . + (512 - ((. - _loader_text_start) % 512));
		_loader_text_end = .;
	} > BTCM
	.fvectors 0x0 : AT (_mfvector)
	{
		_fvector_start = .;
		KEEP(*(.fvectors))
		_fvector_end = .;
	} > ATCM
	.text : AT (_mtext)
	{
		_text_start = .;
		*(.text)
		*(.text.*)
	} > ATCM
	.rvectors : 
	{
		_rvectors_start = .;
		KEEP(*(.rvectors))
		_rvectors_end = .;
	} > ATCM
	.init : 
	{
		*(.init)
		PROVIDE_HIDDEN (__exidx_start = .);
		PROVIDE_HIDDEN (__exidx_end = .);
	} > ATCM
	.fini : 
	{
		*(.fini)
	} > ATCM
	.got : 
	{
		*(.got)
		*(.got.plt)
	} > ATCM
	.rodata : 
	{
		*(.rodata)
		*(.rodata.*)
		_erodata = .;
	} > ATCM
	.eh_frame_hdr : 
	{
		*(.eh_frame_hdr)
	} > ATCM
	.eh_frame : 
	{
		*(.eh_frame)
	} > ATCM
	.jcr : 
	{
		*(.jcr)
	} > ATCM
	.tors : 
	{
		__CTOR_LIST__ = .;
		. = ALIGN(2);
		__ctors = .;
		KEEP(*(.ctors))
		__ctors_end = .;
		__CTOR_END__ = .;
		__DTOR_LIST__ = .;
		___dtors = .;
		KEEP(*(.dtors))
		___dtors_end = .;
		__DTOR_END__ = .;
		. = ALIGN(2);
		_text_end = .;
	} > ATCM
	.data : AT (_mdata)
	{
		_data_start = .;
		*(.data)
		*(.data.*)
		_data_end = .;
	} > ATCM
	.bss : 
	{
		PROVIDE(__bss_start__ = .);
		_bss = .;
		*(.bss)
		*(.bss.*)
		*(COMMON)
		PROVIDE(__bss_end__ = .);
		_ebss = .;
		_end = .;
	} > ATCM
	.heap (NOLOAD) :
	{
		. = ALIGN(16);
		PROVIDE(end = .);
		_HeapStart = .;
		. += 0x00008000;
		PROVIDE(_HeapEnd = .);
	} > ATCM
	.sys_stack (NOLOAD) :
	{
		*(.sys_stack)
		. = ALIGN(16);
		_sys_stack_start = .;
		. += 0x00002000;
		_sys_stack = .;
	} > ATCM
	.svc_stack (NOLOAD) :
	{
		*(.svc_stack)
		. = ALIGN(16);
		_svc_stack_start = .;
		. += 0x00002000;
		_svc_stack = .;
	} > ATCM
	.irq_stack (NOLOAD) :
	{
		*(.irq_stack)
		. = ALIGN(16);
		_irq_stack_start = .;
		. += 0x00001000;
		_irq_stack = .;
	} > ATCM
	.fiq_stack (NOLOAD) :
	{
		*(.fiq_stack)
		. = ALIGN(16);
		_fiq_stack_start = .;
		. += 0x00001000;
		_fiq_stack = .;
	} > ATCM
	.und_stack (NOLOAD)  :
	{
		*(.und_stack)
		. = ALIGN(16);
		_und_stack_start = .;
		. += 0x00001000;
		_und_stack = .;
	} > ATCM
	.abt_stack (NOLOAD)  :
	{
		*(.und_stack)
		. = ALIGN(16);
		_abt_stack_start = .;
		. += 0x00001000;
		_abt_stack = .;
	} > ATCM
}
