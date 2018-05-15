/**
 * @file include/retdec/bin2llvmir/providers/abi/mips.h
 * @brief ABI information for MIPS.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#ifndef RETDEC_BIN2LLVMIR_PROVIDERS_ABI_MIPS_H
#define RETDEC_BIN2LLVMIR_PROVIDERS_ABI_MIPS_H

#include "retdec/bin2llvmir/providers/abi/abi.h"

namespace retdec {
namespace bin2llvmir {

class AbiMips : public Abi
{
	// Ctors, dtors.
	//
	public:
		AbiMips(llvm::Module* m, Config* c);
		virtual ~AbiMips();

	// Instructions.
	//
	public:
		virtual bool isNopInstruction(AsmInstruction ai);
};

} // namespace bin2llvmir
} // namespace retdec

#endif
