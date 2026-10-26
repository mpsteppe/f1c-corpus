int __userpurge sub_5431AB@<eax>(float *a1@<ecx>, unsigned int a2@<edi>, int a3, int a4, int a5)
{
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  void (__thiscall ***v9)(_DWORD, int); // ecx

  a1[1] = 0.0;
  *a1 = 0.0;
  *((_DWORD *)a1 + 2) = a5;
  if ( !(_WORD)a5 || (unsigned __int16)a5 > 5u || (a5 & 0xFFF00000) != 0 )
    return -2005530516;
  *(_DWORD *)(a3 + 64) = a5 & 0x80000;
  v6 = sub_5486AF(a3);
  *((_DWORD *)a1 + 1) = v6;
  if ( !v6 )
    goto LABEL_18;
  v7 = sub_5486AF(a4);
  *(_DWORD *)a1 = v7;
  if ( !v7 )
    goto LABEL_18;
  v8 = sub_544504(v7);
  if ( v8 >= 0 )
  {
    if ( sub_54130E(a1) >= 0
      || sub_541446(a1) >= 0
      || sub_541537(a1) >= 0
      || sub_541739(a1) >= 0
      || sub_54193D(a1, a2, a1) >= 0
      || sub_541D60(a1, a2, a1) >= 0
      || sub_5422F2(a1) >= 0
      || sub_5426D8(a1) >= 0
      || sub_542E09(a1) >= 0
      || sub_53FD37(a1) >= 0 )
    {
      v8 = 0;
      goto LABEL_19;
    }
LABEL_18:
    v8 = -2147467259;
  }
LABEL_19:
  v9 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)a1 + 1);
  if ( v9 )
  {
    (**v9)(v9, 1);
    a1[1] = 0.0;
  }
  if ( *(_DWORD *)a1 )
  {
    (***(void (__thiscall ****)(_DWORD, int))a1)(*(_DWORD *)a1, 1);
    *a1 = 0.0;
  }
  return v8;
}
