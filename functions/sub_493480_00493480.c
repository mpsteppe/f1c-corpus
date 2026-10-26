int __thiscall sub_493480(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // ebx
  _DWORD *v4; // edi
  _DWORD *v5; // ebp
  int v6; // eax
  _DWORD *v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  char v21[4]; // [esp+8h] [ebp-88h] BYREF
  _DWORD *v22; // [esp+Ch] [ebp-84h]
  _BYTE v23[125]; // [esp+10h] [ebp-80h] BYREF
  __int16 v24; // [esp+8Dh] [ebp-3h]
  char v25; // [esp+8Fh] [ebp-1h]

  v23[0] = byte_5EA438[0];
  v3 = this;
  memset(&v23[1], 0, 0x7Cu);
  v24 = 0;
  v25 = 0;
  v4 = a2;
  v22 = this;
  if ( !a2 || !a3 )
    return -1;
  ++this[101];
  if ( sub_491FB0(this) )
  {
    v5 = v22;
    do
    {
      if ( sub_587C20(&unk_7CDB70, asc_5CC4F4) )
        break;
      if ( sub_5654A0(aDoPage, v23) )
      {
        v6 = OperatorNewNhMallocWrapper(28);
        if ( v6 )
          v7 = (_DWORD *)F_7FieldSentineInit(v6);
        else
          v7 = 0;
        *v7 = 1;
        StringCopyWithBufferRealloc(v23);
        goto LABEL_52;
      }
      if ( sub_5654A0(aDoPageTransiti, v23) )
      {
        v8 = OperatorNewNhMallocWrapper(28);
        if ( v8 )
          v7 = (_DWORD *)F_7FieldSentineInit(v8);
        else
          v7 = 0;
        *v7 = 2;
        StringCopyWithBufferRealloc(v23);
        goto LABEL_52;
      }
      if ( sub_5654A0(aDoPageTransiti_0, v23) )
      {
        v9 = OperatorNewNhMallocWrapper(28);
        if ( v9 )
          v7 = (_DWORD *)F_7FieldSentineInit(v9);
        else
          v7 = 0;
        *v7 = 3;
        StringCopyWithBufferRealloc(v23);
        v5 = v7;
        goto LABEL_52;
      }
      if ( sub_5654A0(aDoPageTransiti_1, v23) )
      {
        v10 = OperatorNewNhMallocWrapper(28);
        if ( v10 )
          v7 = (_DWORD *)F_7FieldSentineInit(v10);
        else
          v7 = 0;
        *v7 = 4;
        StringCopyWithBufferRealloc(v23);
        v5 = v7;
        goto LABEL_52;
      }
      if ( sub_5654A0(aDoPageTransiti_2, v23) )
      {
        v11 = OperatorNewNhMallocWrapper(28);
        if ( v11 )
          v7 = (_DWORD *)F_7FieldSentineInit(v11);
        else
          v7 = 0;
        *v7 = 5;
        StringCopyWithBufferRealloc(v23);
        v5 = v7;
        goto LABEL_52;
      }
      if ( sub_5654A0(aDoPageTransiti_3, v23) )
      {
        v12 = OperatorNewNhMallocWrapper(28);
        if ( v12 )
          v7 = (_DWORD *)F_7FieldSentineInit(v12);
        else
          v7 = 0;
        *v7 = 6;
        StringCopyWithBufferRealloc(v23);
        v5 = v7;
        goto LABEL_52;
      }
      if ( sub_5654A0(aTransitionAttr, v23) )
      {
        v5[5] = StringMatchedLinkedListSearch(v23);
      }
      else
      {
        if ( sub_5654A0(aDoLayer, v23) )
        {
          v13 = OperatorNewNhMallocWrapper(28);
          if ( v13 )
            v7 = (_DWORD *)F_7FieldSentineInit(v13);
          else
            v7 = 0;
          *v7 = 7;
          StringCopyWithBufferRealloc(v23);
          goto LABEL_52;
        }
        if ( sub_5654A0(aSetSymbol, v23) )
        {
          strcpy(v21, ":\t");
          v14 = OperatorNewNhMallocWrapper(28);
          if ( v14 )
            v7 = (_DWORD *)F_7FieldSentineInit(v14);
          else
            v7 = 0;
          *v7 = 9;
          v15 = sub_5897CA(v23, v21);
          v16 = sub_5897CA(0, v21);
          if ( v15 )
            StringCopyWithBufferRealloc(v15);
          if ( v16 )
            StringCopyWithBufferRealloc(v16);
          v4 = a2;
          v3 = v22;
          goto LABEL_52;
        }
        if ( sub_5654A0(aDropPopups, v23) )
        {
          v17 = OperatorNewNhMallocWrapper(28);
          if ( v17 )
          {
            v7 = (_DWORD *)F_7FieldSentineInit(v17);
            *v7 = 10;
          }
          else
          {
            v7 = 0;
            MEMORY[0] = 10;
          }
LABEL_52:
          if ( sub_588410(a3, aClick) )
          {
            if ( sub_588410(a3, aRelease) )
            {
              if ( sub_588410(a3, aFocus) )
              {
                if ( !sub_588410(a3, aLostfocus) )
                  LinkedListAppend_6540(v4, (int)v7);
              }
              else
              {
                LinkedListTailAppend(v4, (int)v7);
              }
            }
            else
            {
              LinkedListAppend(v4, (int)v7);
            }
          }
          else
          {
            AppendToLinkedListTail(v4, (int)v7);
          }
          continue;
        }
        if ( sub_5654A0(aExitGame, v23) )
        {
          v18 = OperatorNewNhMallocWrapper(28);
          if ( v18 )
          {
            v7 = (_DWORD *)F_7FieldSentineInit(v18);
            *v7 = 11;
          }
          else
          {
            v7 = 0;
            MEMORY[0] = 11;
          }
          goto LABEL_52;
        }
        if ( sub_5654A0(aSimulateclick, v23) )
        {
          v19 = OperatorNewNhMallocWrapper(28);
          if ( v19 )
            v7 = (_DWORD *)F_7FieldSentineInit(v19);
          else
            v7 = 0;
          *v7 = 12;
          StringCopyWithBufferRealloc(v23);
          goto LABEL_52;
        }
      }
    }
    while ( sub_491FB0(v3) );
  }
  --v3[101];
  return 0;
}
