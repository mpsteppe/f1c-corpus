// positive sp value has been detected, the output may be wrong!
int __userpurge sub_49F3D9@<eax>(
        char a1@<zf>,
        char a2@<sf>,
        char a3@<of>,
        int a4@<eax>,
        int a5@<edx>,
        int a6@<ecx>,
        int a7@<ebx>,
        int a8@<ebp>,
        int a9@<esi>,
        int a10,
        int a11,
        int a12,
        int a13)
{
  const char *v13; // edi
  void *v14; // ecx
  void *v15; // edx
  int v16; // eax
  int v17; // edi
  int v18; // ebp
  int v20; // [esp-88Ch] [ebp-88Ch]
  _BYTE *v21; // [esp-888h] [ebp-888h]
  int v25; // [esp-878h] [ebp-878h]
  int v26; // [esp-874h] [ebp-874h] BYREF
  int v27; // [esp-870h] [ebp-870h] BYREF
  int v28; // [esp-86Ch] [ebp-86Ch] BYREF
  _DWORD v29[62]; // [esp-868h] [ebp-868h] BYREF
  LPVOID v30[101]; // [esp-770h] [ebp-770h] BYREF
  _BYTE v31[1500]; // [esp-5DCh] [ebp-5DCh] BYREF

  if ( a2 ^ a3 | a1 )
    return 0;
  v13 = v31;
  v21 = v31;
  while ( !strlen(v13) )
  {
LABEL_9:
    ++a9;
    v13 = v21 + 100;
    v21 += 100;
    if ( a9 >= v20 )
      return 0;
  }
  sub_49EC20(v30, 1, -1);
  sub_49ECE0(v30, v29[a9 + 16]);
  v14 = *(void **)(a8 + 152);
  v15 = *(void **)(a8 + 156);
  v30[12] = *(LPVOID *)(a8 + 48);
  v30[38] = v14;
  v30[39] = v15;
  sub_578600(v21);
  v16 = v29[a9 + 2];
  v17 = a7 + v29[a9 + 1];
  if ( v16 <= 0 )
    v18 = a6;
  else
    v18 = a7 + v16 - v29[a9 + 31];
  if ( v17 <= v18 )
  {
    sub_4B13F0(a5, a4, v17, v18);
    sub_49ECF0(v30, v18 - v17);
    sub_49F130(v30, v29, &v26, &v28, &v27);
    sub_49EC50(v30);
    a8 = v25;
    goto LABEL_9;
  }
  sub_49EC50(v30);
  return -1;
}
