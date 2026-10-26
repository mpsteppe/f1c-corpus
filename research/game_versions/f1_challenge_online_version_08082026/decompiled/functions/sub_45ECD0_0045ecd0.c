int __thiscall sub_45ECD0(_DWORD *this)
{
  int v2; // esi
  LPVOID **v3; // ebp
  char v4; // al
  LPVOID *v5; // edi
  char *v6; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  _DWORD *v10; // eax
  _DWORD *v11; // esi
  int v12; // eax
  _BYTE v14[28]; // [esp+10h] [ebp-634h] BYREF
  _BYTE v15[253]; // [esp+2Ch] [ebp-618h] BYREF
  __int16 v16; // [esp+129h] [ebp-51Bh]
  char v17; // [esp+12Bh] [ebp-519h]
  _BYTE v18[384]; // [esp+12Ch] [ebp-518h] BYREF
  int v19; // [esp+2ACh] [ebp-398h]
  char v20; // [esp+2B0h] [ebp-394h]
  int v21; // [esp+2B8h] [ebp-38Ch]
  int v22; // [esp+2BCh] [ebp-388h]
  int v23; // [esp+2C0h] [ebp-384h]
  _BYTE v24[384]; // [esp+2C4h] [ebp-380h] BYREF
  char v25[509]; // [esp+444h] [ebp-200h] BYREF
  __int16 v26; // [esp+641h] [ebp-3h]
  char v27; // [esp+643h] [ebp-1h]

  v2 = this[28128];
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        if ( *v5 )
          sub_587BCF(*v5);
        sub_587BCF(v5);
      }
    }
    sub_587BCF(v3);
  }
  this[28128] = 0;
  this[28129] = 0;
  this[28130] = 0;
  this[28131] = 0;
  v25[0] = byte_5EA438[0];
  memset(&v25[1], 0, 0x1FCu);
  v26 = 0;
  v27 = 0;
  sub_5668B0(v14);
  sub_4B0220(v25, 511);
  v6 = &v25[strlen(v25) + 1];
  v7 = dword_5C5E64;
  v8 = dword_5C5E68;
  *(_DWORD *)--v6 = dword_5C5E60;
  v9 = dword_5C5E6C;
  *((_DWORD *)v6 + 1) = v7;
  LOWORD(v7) = word_5C5E70;
  *((_DWORD *)v6 + 2) = v8;
  *((_DWORD *)v6 + 3) = v9;
  *((_WORD *)v6 + 8) = v7;
  if ( (unsigned __int8)sub_566B20(v25, 1) )
  {
    memset(v24, 0, sizeof(v24));
    v15[0] = byte_5EA438[0];
    memset(&v15[1], 0, 0xFCu);
    v16 = 0;
    v17 = 0;
    v19 = 0;
    v23 = 0;
    v21 = 0;
    v22 = 0;
    v20 = 1;
    while ( sub_566CC0(v24, 384) )
    {
      if ( !sub_5651B0(v18)
        && (sub_5654A0(aAutochat01, v15)
         || sub_5654A0(aAutochat02, v15)
         || sub_5654A0(aAutochat03, v15)
         || sub_5654A0(aAutochat04, v15)
         || sub_5654A0(aAutochat05, v15)
         || sub_5654A0(aAutochat06, v15)
         || sub_5654A0(aAutochat07, v15)
         || sub_5654A0(aAutochat08, v15)
         || sub_5654A0(aAutochat09, v15)
         || sub_5654A0(aAutochat10, v15)) )
      {
        v10 = (_DWORD *)sub_587C03(8);
        v11 = v10;
        if ( v10 )
        {
          *v10 = 0;
          v10[1] = -1;
          sub_566650(v15);
        }
        else
        {
          v11 = 0;
        }
        if ( v11 )
        {
          v12 = sub_587C03(12);
          if ( v12 )
          {
            *(_DWORD *)v12 = v11;
            *(_DWORD *)(v12 + 4) = 0;
            *(_BYTE *)(v12 + 8) = 1;
          }
          else
          {
            v12 = 0;
          }
          if ( this[28128] )
          {
            *(_DWORD *)(this[28129] + 4) = v12;
          }
          else
          {
            this[28128] = v12;
            this[28130] = v12;
          }
          this[28129] = v12;
          ++this[28131];
        }
        if ( (int)this[28131] >= 10 )
          break;
      }
    }
    sub_566B90(v14);
  }
  return sub_5668D0(v14);
}
