int __thiscall sub_44E090(_DWORD *this, char *FileName, int *a3)
{
  void *v4; // eax
  int v5; // edi
  int *v6; // eax
  _DWORD *v7; // ebx
  _DWORD *v8; // edx
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  _DWORD *v13; // ecx
  _DWORD *v14; // eax
  _DWORD *v15; // ecx
  _DWORD *v16; // ebx
  int i; // edi
  int v18; // esi
  int v19; // eax
  int Buffer; // [esp+0h] [ebp-44h] BYREF
  int v22; // [esp+4h] [ebp-40h] BYREF
  int v23; // [esp+8h] [ebp-3Ch] BYREF
  int v24[10]; // [esp+Ch] [ebp-38h] BYREF
  int v25; // [esp+34h] [ebp-10h]
  int v26; // [esp+38h] [ebp-Ch]
  int v27; // [esp+3Ch] [ebp-8h]
  LPVOID v28; // [esp+40h] [ebp-4h]

  sub_57A080(v24);
  sub_57AF60(FileName);
  sub_57A110(FileName, 4, 0, 1);
  sub_57A3A0(aVer006ThisFile, 0x2Eu);
  sub_57A3A0(this + 2, 8u);
  sub_57A3A0(this + 4, 8u);
  sub_57A3A0(this + 6, 8u);
  sub_57A3A0(this + 8, 8u);
  Buffer = *a3;
  sub_57A3A0(&Buffer, 4u);
  v4 = operator new(92 * Buffer);
  *this = v4;
  v24[9] = (int)v4;
  v24[8] = Buffer;
  v24[7] = 0;
  v28 = operator new(16 * Buffer);
  v23 = sub_44E050(Buffer);
  sub_57A3A0(&v23, 4u);
  v5 = v23;
  v6 = (int *)operator new(16 * v23 + 4);
  if ( v6 )
  {
    v7 = v6 + 1;
    *v6 = v5;
    v8 = v6 + 1;
    if ( v5 - 1 >= 0 )
    {
      do
      {
        sub_44C870(v8);
        v8 = (_DWORD *)(v9 + 16);
        --v5;
      }
      while ( v5 );
    }
    v10 = (int)v7;
  }
  else
  {
    v10 = 0;
  }
  v11 = v23;
  this[1] = v10;
  v27 = v10;
  v12 = 0;
  v26 = v11;
  v13 = (_DWORD *)a3[3];
  v25 = 0;
  if ( v13 )
    v12 = sub_44AAE0(v13);
  v22 = v12;
  sub_57A3A0(&v22, 4u);
  v14 = operator new(4 * v22);
  v15 = (_DWORD *)a3[3];
  v16 = v14;
  if ( v15 )
    sub_44AB20(v15, (int)v14, 0);
  for ( i = 0; i < v22; ++i )
  {
    v18 = v16[i];
    sub_57A3A0((void *)v18, 4u);
    sub_57A3A0((void *)(v18 + 16), 8u);
    sub_57A3A0((void *)(v18 + 12), 4u);
  }
  v19 = sub_44BB10(a3);
  if ( v19 )
  {
    v25 = 1;
    sub_44C8F0(v27, *(float *)&v19, (int)v24);
  }
  if ( v16 )
    sub_5BE8AE(v16);
  if ( v28 )
    sub_5BE8AE(v28);
  sub_57A360(v24);
  sub_57A0A0(v24);
  return 0;
}
