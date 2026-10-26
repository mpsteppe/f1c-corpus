int __userpurge sub_5063A5@<eax>(int *a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4, int a5, int a6)
{
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  void (__thiscall ***v10)(_DWORD, int); // ecx

  a1[1] = 0;
  *a1 = 0;
  a1[2] = a6;
  if ( !(_WORD)a6 || (unsigned __int16)a6 > 5u || (a6 & 0xFFF00000) != 0 )
    return -2005530516;
  *(_DWORD *)(a4 + 64) = a6 & 0x80000;
  v7 = sub_50B8A9(a4);
  a1[1] = v7;
  if ( !v7 )
    goto LABEL_18;
  v8 = sub_50B8A9(a5);
  *a1 = v8;
  if ( !v8 )
    goto LABEL_18;
  v9 = sub_5076FE(v8);
  if ( v9 >= 0 )
  {
    if ( sub_504508(a1) >= 0
      || sub_504640(a2) >= 0
      || sub_504731(a2) >= 0
      || sub_504933(a2) >= 0
      || sub_504B37(v9, a2, a3, (int)a1) >= 0
      || sub_504F5A(v9, a2, a3, (int)a1) >= 0
      || sub_5054EC(a2) >= 0
      || sub_5058D2(a2) >= 0
      || sub_506003(a2) >= 0
      || sub_502F31(a2) >= 0 )
    {
      v9 = 0;
      goto LABEL_19;
    }
LABEL_18:
    v9 = -2147467259;
  }
LABEL_19:
  v10 = (void (__thiscall ***)(_DWORD, int))a1[1];
  if ( v10 )
  {
    (**v10)(v10, 1);
    a1[1] = 0;
  }
  if ( *a1 )
  {
    (**(void (__thiscall ***)(int, int))*a1)(*a1, 1);
    *a1 = 0;
  }
  return v9;
}
