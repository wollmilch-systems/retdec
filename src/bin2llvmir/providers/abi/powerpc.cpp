/**
 * @file src/bin2llvmir/providers/abi/powerpc.h
 * @brief ABI information for PowerPC.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#include "retdec/bin2llvmir/providers/abi/powerpc.h"

using namespace llvm;

namespace retdec {
namespace bin2llvmir {

AbiPowerpc::AbiPowerpc(llvm::Module* m, Config* c) :
		Abi(m, c)
{
	_regs.reserve(PPC_REG_ENDING);
	_id2regs.resize(PPC_REG_ENDING, nullptr);
	_regStackPointerId = PPC_REG_R1;
}

AbiPowerpc::~AbiPowerpc()
{

}

bool AbiPowerpc::isNopInstruction(AsmInstruction ai)
{
	cs_insn* insn = ai.getCapstoneInsn();
	cs_ppc& insnPpc = insn->detail->ppc;

	// True NOP variants.
	//
	if (insn->id == PPC_INS_NOP
			|| insn->id == PPC_INS_XNOP)
	{
		return true;
	}

	return false;
}

} // namespace bin2llvmir
} // namespace retdec
