int __usercall sub_416CC0@<eax>(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        int a4@<ebx>,
        int a5@<ebp>,
        int a6@<edi>,
        int _ESI@<esi>,
        float a8,
        float a9,
        char a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        float a22)
{
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  __asm { fstp    [esp+20h+arg_38] }
  sub_614B90(a1, a2, a3, a4, &retaddr, a5, a6, _ESI);
  sub_51A520(&a10);
  __asm
  {
    fld     qword ptr [esi+68h]
    fstp    dword ptr [esp+20h]
  }
  __asm { fld     qword ptr [esi+70h] }
  __asm { fstp    [esp+24h+arg_0] }
  __asm
  {
    fld     qword ptr [esi+78h]
    fstp    [esp+24h+arg_4]
  }
  sub_4164C0((__int16 *)(a4 + 22), (float *)&retaddr);
  __asm { fld     qword ptr [esi+80h] }
  __asm { fstp    dword ptr [esp+20h] }
  __asm { fld     qword ptr [esi+88h] }
  __asm
  {
    fstp    [esp+24h+arg_0]
    fld     qword ptr [esi+90h]
    fstp    [esp+24h+arg_4]
  }
  return sub_4165B0((__int16 *)(a4 + 28), (float *)&retaddr);
}
