void __thiscall sub_5F5470(_BYTE *this, int a2, int a3, char *Block)
{
  char *v4; // ebx
  int v5; // ebp
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  int *v8; // edi
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int v19; // [esp+18h] [ebp-38h] BYREF
  int v20; // [esp+1Ch] [ebp-34h]
  int v21; // [esp+20h] [ebp-30h]
  int v22; // [esp+34h] [ebp-1Ch]
  int v23; // [esp+38h] [ebp-18h]
  int v24; // [esp+3Ch] [ebp-14h]
  void *Blocka; // [esp+5Ch] [ebp+Ch]

  v4 = Block;
  flt_910F1C = (float)-*(_DWORD *)(dword_FB27A4 + 9408);
  flt_910F3C = (float)-*(_DWORD *)(dword_FB27A4 + 9412);
  v5 = 0;
  v6 = operator new(32 * (_DWORD)Block);
  Blocka = v6;
  if ( (int)v4 > 0 )
  {
    v7 = v6 + 2;
    v8 = (int *)(a2 + 8);
    do
    {
      v9 = *(v8 - 1);
      v10 = *v8;
      v19 = *(v8 - 2);
      v22 = v8[1];
      v20 = v9;
      v11 = v8[2];
      v21 = v10;
      v12 = v8[3];
      v23 = v11;
      v24 = v12;
      if ( sub_5F52C0((float *)&v19) )
      {
        v13 = v20;
        v14 = v21;
        *(v7 - 2) = v19;
        v15 = v22;
        *(v7 - 1) = v13;
        v16 = v23;
        *v7 = v14;
        v17 = v24;
        v7[1] = v15;
        v7[2] = v16;
        v7[3] = v17;
        ++v5;
        v7 += 8;
      }
      v8 += 8;
      --v4;
    }
    while ( v4 );
    if ( v5 > 0 && (*this & 0x40) != 0 )
      (*(void (__thiscall **)(int, _BYTE *, void *, int, int))(*(_DWORD *)dword_FB27A4 + 488))(
        dword_FB27A4,
        this,
        Blocka,
        a3,
        v5);
  }
  *(_DWORD *)this &= ~0x100u;
  j__free(Blocka);
}
