// Address: 0x004319da
// Size: 116 bytes
// Name: sub_4319DA
// Type: int __userpurge@<eax>(int _EAX@<eax>, int _ECX@<ecx>, int@<ebx>, int, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
int __userpurge sub_4319DA@<eax>(int _EAX@<eax>, int _ECX@<ecx>, int a3@<ebx>, int a4, int a5)
{
  double v6; // [esp-8h] [ebp-14h]
  const char *v7; // [esp+0h] [ebp-Ch]
  double v8; // [esp+4h] [ebp-8h]

  LOBYTE(_EAX) = BYTE1(_ECX) + _EAX;
  if ( (_EAX & 0x80u) != 0 )
  {
    ++*(_DWORD *)(a3 + 1149962476);
    LOBYTE(_EAX) = _EAX & 0xC;
    __asm { fld     dword ptr [ecx+eax*4+1CD8h] }
    __asm { fmul    ds:dbl_59EA20 }
    v7 = (const char *)(_ECX + 24);
    __asm { fstp    qword ptr [esp+4] }
    if ( *(_DWORD *)(_ECX + 4) == 1 )
      return sub_58815F(a5, "%.2f %s", v8, v7);
    __asm { fld     qword ptr [esp+4] }
  }
  __asm { fmul    ds:dbl_59EA18 }
  __asm { fstp    qword ptr [esp+0Ch+var_C] }
  return sub_58815F(a5, "%.3f %s", v6, v7);
}
