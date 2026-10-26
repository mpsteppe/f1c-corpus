int __usercall sub_63DDA5@<eax>(
        int a1@<eax>,
        int a2@<ecx>,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  int v11; // edi
  int v13; // edx
  int result; // eax
  int v15; // esi
  int v16; // edx
  int v17; // esi
  int v18; // esi
  int v19; // ecx
  int v20; // ecx
  bool v21; // sf
  int v22; // ecx
  int v23; // ecx
  int v24; // esi
  int v25; // [esp+20h] [ebp+Ch]

  v11 = a5;
  v13 = a5 % 4;
  if ( a4 == 1 )
  {
    if ( v13 || !(a5 % 100) )
      return off_16C9600();
    v25 = a1;
    v15 = dword_9137D8[a1] + 1;
    v11 = a5;
    v16 = (365 * a5 + (a5 + 299) / 400 - (a5 - 1) / 100 + v15 + (a5 - 1) / 4 - 25563) % 7;
    result = a7 + 7 * a6 - v16;
    if ( v16 > a7 )
      v17 = result + v15;
    else
      v17 = v15 + result - 7;
    if ( a6 == 5 )
    {
      if ( a5 % 100 || !((a5 + 1900) % 400) )
        result = dword_9137DC[v25];
      else
        result = dword_913810[v25];
      if ( v17 > result )
        v17 -= 7;
    }
  }
  else
  {
    if ( (v13 || (result = a5 / 100, !(a5 % 100))) && (result = (a5 + 1900) / 400, (a5 + 1900) % 400) )
      v18 = dword_91380C[a1];
    else
      v18 = dword_9137D8[a1];
    v17 = a8 + v18;
  }
  v19 = 60 * (a9 + 60 * a2);
  if ( a3 == 1 )
  {
    dword_91341C = v17;
    dword_913418 = v11;
    dword_913420 = a11 + 1000 * (a10 + v19);
    return result;
  }
  dword_913428 = v17;
  v20 = 1000 * (a10 + dword_913388 + v19);
  v21 = a11 + v20 < 0;
  v22 = a11 + v20;
  dword_91342C = v22;
  if ( v21 )
  {
    v23 = v22 + 86400000;
    v24 = v17 - 1;
LABEL_27:
    dword_91342C = v23;
    dword_913428 = v24;
    goto LABEL_28;
  }
  result = 86400000;
  if ( v22 >= 86400000 )
  {
    v23 = v22 - 86400000;
    v24 = v17 + 1;
    goto LABEL_27;
  }
LABEL_28:
  dword_913424 = v11;
  return result;
}
