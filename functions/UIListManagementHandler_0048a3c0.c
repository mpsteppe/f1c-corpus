int __thiscall sub_48A3C0(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int v5; // edi
  int v6; // esi
  char *v7; // eax
  int v8; // ebx
  int v9; // edi
  char *v10; // eax
  char *v11; // esi
  int v12; // ebx
  int v13; // ebx
  int j; // esi
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  int v18; // esi
  char v19; // [esp+Fh] [ebp-2Dh]
  int v20; // [esp+10h] [ebp-2Ch]
  int v21; // [esp+14h] [ebp-28h]
  int v22; // [esp+18h] [ebp-24h]
  int i; // [esp+1Ch] [ebp-20h]
  int v24; // [esp+20h] [ebp-1Ch]
  int v25; // [esp+24h] [ebp-18h]
  int v26; // [esp+28h] [ebp-14h]
  int v27; // [esp+2Ch] [ebp-10h]
  int v28; // [esp+30h] [ebp-Ch]

  result = this[90];
  v5 = this[37];
  v6 = 0;
  v26 = -1;
  v27 = result;
  v28 = v5;
  v25 = 0;
  v24 = v5;
  if ( v5 > 0 )
  {
    while ( 1 )
    {
      v21 = ShortComputation_63c0(this, 0);
      this[90] = 0;
      v7 = a3 >= 0 ? (char *)UITextFormatHelper((int)this, a3) : UIScreenTextAccessor(this);
      StringCopyWithBufferRealloc(v7);
      v8 = 0;
      v19 = 0;
      v20 = 0;
      v22 = 0;
      for ( i = 0; ; v6 = i )
      {
        v9 = ShortComputation_63c0(this, v6);
        this[90] = v6;
        if ( a3 >= 0 )
          v10 = (char *)UITextFormatHelper((int)this, a3);
        else
          v10 = UIScreenTextAccessor(this);
        v11 = v10;
        if ( v10 )
        {
          switch ( a2 )
          {
            case 0:
              v12 = sub_587ECE(byte_5EA438);
              if ( sub_587ECE(v11) >= v12 )
                goto LABEL_18;
              goto LABEL_16;
            case 1:
              v13 = sub_587ECE(byte_5EA438);
              if ( sub_587ECE(v11) > v13 )
              {
LABEL_16:
                v21 = v9;
                StringCopyWithBufferRealloc(v11);
                v8 = v22;
                v20 = v22;
              }
              else
              {
LABEL_18:
                v8 = v22;
              }
              break;
            case 2:
              if ( (int)sub_588410(v10, byte_5EA438) < 0 )
                goto LABEL_30;
              break;
            case 3:
              if ( (int)sub_588410(v10, byte_5EA438) > 0 )
              {
LABEL_30:
                v21 = v9;
                StringCopyWithBufferRealloc(v11);
                v20 = v8;
              }
              break;
            default:
              break;
          }
          v22 = ++v8;
        }
        if ( ++i >= v24 )
          break;
      }
      j = 0;
      if ( v20 == v27 )
        v19 = 1;
      v15 = UtilityFunction_6400(this, v21);
      if ( v15 )
      {
        v16 = v25;
        if ( v25 )
        {
          v17 = *(_DWORD *)(v25 + 140);
          for ( j = 1; v17; ++j )
          {
            v16 = v17;
            v17 = *(_DWORD *)(v17 + 140);
          }
          *(_DWORD *)(v16 + 140) = v15;
        }
        else
        {
          v25 = v15;
        }
      }
      if ( v19 )
        v26 = j;
      result = 0;
      v18 = this[37];
      --this[90];
      v24 = v18;
      if ( v18 <= 0 )
        break;
      v6 = 0;
    }
    v5 = v28;
  }
  if ( !this[36] )
  {
    this[36] = v25;
    this[37] = v5;
    return UIListSelectionHandler(this, v26, 0);
  }
  return result;
}
