int __usercall sub_4FA6A0@<eax>(int *a1@<ecx>, int a2@<ebx>, float a3@<edi>)
{
  int result; // eax
  int v5; // ebx
  int v6; // edi
  int v7; // ecx
  char v8; // al
  int v9; // ecx
  int v10; // ebx
  _DWORD *v11; // edi
  int v12; // edx
  float v13; // [esp+0h] [ebp-60h] BYREF
  int v14; // [esp+4h] [ebp-5Ch]
  float v15; // [esp+8h] [ebp-58h]
  float v16[2]; // [esp+Ch] [ebp-54h] BYREF
  float v17; // [esp+14h] [ebp-4Ch]
  char v18[12]; // [esp+18h] [ebp-48h] BYREF
  float v19[3]; // [esp+24h] [ebp-3Ch] BYREF
  float v20[12]; // [esp+30h] [ebp-30h] BYREF

  result = a1[75];
  if ( result )
  {
    result = *a1;
    if ( *a1 )
    {
      v14 = a2;
      v13 = a3;
      sub_54FDB0(&unk_FADD40, result, v20, v19);
      sub_5773F0(&v13);
      sub_614A90(v18, v20);
      v16[1] = 0.0;
      v16[0] = -v13;
      v13 = v16[0];
      v17 = -v15;
      v14 = 0;
      v15 = v17;
      sub_416420(v20, v19, &v13, v16);
      sub_4F1B60();
      sub_5DB320(1, 0, 0);
      v5 = 0;
      if ( a1[72] > 0 )
      {
        v6 = 0;
        do
        {
          v7 = a1[73];
          v8 = *(_BYTE *)(v7 + v6 + 9);
          v9 = v6 + v7;
          if ( v8 )
            sub_4F4510(v9);
          ++v5;
          v6 += 768;
        }
        while ( v5 < a1[72] );
      }
      a1[1] = 105;
      result = dword_757C10;
      v10 = 0;
      if ( dword_757C10 > 0 )
      {
        while ( 1 )
        {
          v11 = (_DWORD *)*(&dword_91E088 + v10);
          if ( v11 != (_DWORD *)*a1 && v11[3705] != -1 && *(_DWORD *)(*a1 + 22548) == v11[5637] )
          {
            result = sub_4FB7D0(v11 + 3706);
            if ( result )
              break;
          }
          result = dword_757C10;
          if ( ++v10 >= dword_757C10 )
            return result;
        }
        v12 = *a1;
        a1[1] = v11[5617];
        *(_DWORD *)(result + 4) = *(_DWORD *)(v12 + 22468);
        if ( (*(_BYTE *)(result + 12) & 0x20) == 0 )
          return sub_4F7EC0(a1, 1, 0);
      }
    }
  }
  return result;
}
