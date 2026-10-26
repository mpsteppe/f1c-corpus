int __thiscall sub_477830(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // edi
  _DWORD *v3; // ebx
  char v4; // al
  int v5; // eax
  int v6; // edi
  int v7; // ebp
  _DWORD *v8; // eax
  _DWORD *v9; // ebx
  char *v10; // eax
  char v11; // cl
  int v12; // ecx
  char *v13; // eax
  const char *v14; // ebp
  __int16 v15; // dx
  char *v16; // edi
  int v17; // ecx
  int v18; // eax
  int v21; // [esp+14h] [ebp-150h]
  int v22; // [esp+18h] [ebp-14Ch]
  int v23; // [esp+1Ch] [ebp-148h]
  _BYTE v24[61]; // [esp+24h] [ebp-140h] BYREF
  __int16 v25; // [esp+61h] [ebp-103h]
  char v26; // [esp+63h] [ebp-101h]
  char v27[253]; // [esp+64h] [ebp-100h] BYREF
  __int16 v28; // [esp+161h] [ebp-3h]
  char v29; // [esp+163h] [ebp-1h]

  v1 = this;
  UIDimensionCapture();
  v2 = v1[60];
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 12);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 && *v3 )
      (**(void (__thiscall ***)(_DWORD, int))*v3)(*v3, 1);
    FreeWrapper_7bcf(v3);
  }
  v1[60] = 0;
  v1[61] = 0;
  v1[62] = 0;
  v1[63] = 0;
  ResourceListCleanup_62c0(v1 + 96);
  v5 = ConditionalDispatch_81f0(aGameFilter);
  SceneFileFilterBuilder(v5);
  v6 = 0;
  v23 = ReadFieldAtOffset0x14(v1 + 96);
  v21 = 0;
  if ( v23 > 0 )
  {
    do
    {
      v7 = LinkedListRandomAccess(v6);
      v22 = v7;
      if ( v7 )
      {
        v8 = (_DWORD *)OperatorNewNhMallocWrapper(72);
        if ( v8 )
        {
          v9 = UIObjectInit(v8);
          if ( v9 )
          {
            v27[0] = byte_5EA438[0];
            memset(&v27[1], 0, 0xFCu);
            v28 = 0;
            v29 = 0;
            v10 = (char *)(v7 + 4);
            do
            {
              v11 = *v10;
              v27[(_DWORD)v10 - 4 - v7] = *v10;
              ++v10;
            }
            while ( v11 );
            v12 = strlen(v27);
            if ( v12 > 0 )
            {
              v13 = &v27[v12];
              while ( v13 >= v27 )
              {
                if ( *v13 == 92 )
                  break;
                *v13 = 0;
                if ( v13 > v27 )
                  --v13;
              }
            }
            v14 = (const char *)(v7 + 260);
            strcat(v27, v14);
            v15 = word_5C7158;
            v16 = &v27[strlen(v27) + 1];
            v17 = dword_5C7154;
            *(_DWORD *)--v16 = dword_5C7150;
            *((_DWORD *)v16 + 1) = v17;
            *((_WORD *)v16 + 4) = v15;
            v18 = sub_497AD0(v27, 0);
            if ( v18 || (v18 = sub_497AD0(aDfcariconBmp, 0)) != 0 )
              StructFieldCopy_fc80(v18);
            TrackSceneLoader(v14);
            v24[0] = byte_5EA438[0];
            memset(&v24[1], 0, 0x3Cu);
            v25 = 0;
            v26 = 0;
            TrackNameReader(v24, 63);
            StringCopyWithBufferRealloc(v24);
            StringCopyWithBufferRealloc(v14);
            v9[15] = v22;
            DoublyLinkedListAppend_f5d0(v9, 1);
            v1 = this;
            v6 = v21;
          }
        }
      }
      v21 = ++v6;
    }
    while ( v6 < v23 );
  }
  SceneListSearchByPath(v1);
  UIViewportLayoutCalculator(v1);
  return 0;
}
