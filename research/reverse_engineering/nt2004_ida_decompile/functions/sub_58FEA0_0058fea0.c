BOOL __cdecl sub_58FEA0(unsigned __int8 a1, char a2, int a3)
{
  return (a1 & (unsigned __int8)(~a2 & *(_BYTE *)(a3 + 2))) == ((unsigned __int8)(~a2 & *(_BYTE *)(a3 + 2))
                                                              & *(_BYTE *)(a3 + 3));
}
