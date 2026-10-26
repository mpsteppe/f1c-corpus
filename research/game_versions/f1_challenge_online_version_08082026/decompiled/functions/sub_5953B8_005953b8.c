int __cdecl sub_5953B8(unsigned __int16 *a1, unsigned int *a2, int *a3)
{
  unsigned __int16 v4; // bx
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // ebx
  int v8; // esi
  int result; // eax
  int v10; // eax
  int v11; // esi
  int v12; // esi
  int v13; // edi
  unsigned int v14; // esi
  unsigned int v15; // edx
  int v16; // [esp-8h] [ebp-2Ch]
  int v17; // [esp-4h] [ebp-28h]
  int v18; // [esp-4h] [ebp-28h]
  _DWORD v19[3]; // [esp+Ch] [ebp-18h] BYREF
  int v20; // [esp+18h] [ebp-Ch] BYREF
  unsigned int v21; // [esp+1Ch] [ebp-8h]
  int v22; // [esp+20h] [ebp-4h]
  int v23; // [esp+2Ch] [ebp+8h]

  v4 = a1[5];
  v23 = v4 & 0x8000;
  v20 = *(_DWORD *)(a1 + 3);
  v5 = *(_DWORD *)(a1 + 1);
  v6 = *a1;
  v7 = (v4 & 0x7FFF) - 0x3FFF;
  v21 = v5;
  v22 = v6 << 16;
  if ( v7 != -16383 )
  {
    sub_5952E9((int)v19, &v20);
    if ( sub_59525D((int)&v20, a3[2]) )
      ++v7;
    v10 = a3[1];
    if ( v7 >= v10 - a3[2] )
    {
      if ( v7 > v10 )
      {
        if ( v7 >= *a3 )
        {
          sub_595304(&v20);
          v16 = a3[3];
          HIBYTE(v20) |= 0x80u;
          sub_59532B(&v20, v16);
          v8 = *a3 + a3[5];
          v17 = 1;
          goto LABEL_5;
        }
        v18 = a3[3];
        v12 = a3[5];
        HIBYTE(v20) &= ~0x80u;
        v8 = v7 + v12;
        sub_59532B(&v20, v18);
        goto LABEL_16;
      }
      v11 = v10 - v7;
      sub_5952E9((int)&v20, v19);
      sub_59532B(&v20, v11);
      sub_59525D((int)&v20, a3[2]);
      sub_59532B(&v20, a3[3] + 1);
    }
    else
    {
      sub_595304(&v20);
    }
    v8 = 0;
    goto LABEL_4;
  }
  v8 = 0;
  if ( !sub_595310(&v20) )
  {
    sub_595304(&v20);
LABEL_4:
    v17 = 2;
LABEL_5:
    result = v17;
    goto LABEL_17;
  }
LABEL_16:
  result = 0;
LABEL_17:
  v13 = a3[4];
  v14 = v20 | (v23 != 0 ? 0x80000000 : 0) | (v8 << (31 - *((_BYTE *)a3 + 12)));
  if ( v13 == 64 )
  {
    v15 = v21;
    a2[1] = v14;
    *a2 = v15;
  }
  else if ( v13 == 32 )
  {
    *a2 = v14;
  }
  return result;
}
