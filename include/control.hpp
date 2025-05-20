enum class ALUOp{
    ADD, SUB,
    AND, OR, XOR,
    CMP_EQ, CMP_LT, //equal, left little
    PASS_A //傳回A 不做運算
};