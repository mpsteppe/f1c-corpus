int __thiscall sub_4A9DB0(_DWORD *this, _DWORD *a2, char *String1)
{
  void *v4; // eax
  _DWORD *v5; // esi
  void *v6; // eax
  void *v7; // eax
  void *v8; // eax
  void *v9; // eax
  void *v10; // eax
  _BYTE v12[128]; // [esp+Ch] [ebp-80h] BYREF

  v12[0] = byte_629120;
  memset(&v12[1], 0, 127);
  if ( !a2 || !String1 )
    return -1;
  ++this[119];
  if ( sub_4A84A0(this) )
  {
    while ( 1 )
    {
      if ( strstr(Str, asc_608AB4) )
        goto LABEL_40;
      if ( sub_577E50(byte_7656E8, aDoPage, (int)v12) )
        break;
      if ( sub_577E50(byte_7656E8, aDoLayer, (int)v12) )
      {
        v6 = operator new(0x1Cu);
        if ( v6 )
        {
          v5 = (_DWORD *)sub_4B1260(v6);
          *v5 = 2;
        }
        else
        {
          v5 = 0;
          MEMORY[0] = 2;
        }
        goto LABEL_8;
      }
      if ( sub_577E50(byte_7656E8, aDropPopups, (int)v12) )
      {
        v7 = operator new(0x1Cu);
        if ( v7 )
        {
          v5 = (_DWORD *)sub_4B1260(v7);
          *v5 = 4;
        }
        else
        {
          v5 = 0;
          MEMORY[0] = 4;
        }
        goto LABEL_31;
      }
      if ( sub_577E50(byte_7656E8, aDoLastPage, (int)v12) )
      {
        v8 = operator new(0x1Cu);
        if ( v8 )
        {
          v5 = (_DWORD *)sub_4B1260(v8);
          *v5 = 7;
        }
        else
        {
          v5 = 0;
          MEMORY[0] = 7;
        }
        goto LABEL_31;
      }
      if ( sub_577E50(byte_7656E8, aExitGame, (int)v12) )
      {
        v9 = operator new(0x1Cu);
        if ( v9 )
        {
          v5 = (_DWORD *)sub_4B1260(v9);
          *v5 = 5;
        }
        else
        {
          v5 = 0;
          MEMORY[0] = 5;
        }
        goto LABEL_31;
      }
      if ( sub_577E50(byte_7656E8, aSimulateclick, (int)v12) )
      {
        v10 = operator new(0x1Cu);
        if ( v10 )
          v5 = (_DWORD *)sub_4B1260(v10);
        else
          v5 = 0;
        *v5 = 6;
        sub_578600(v12);
        goto LABEL_31;
      }
LABEL_39:
      if ( !sub_4A84A0(this) )
        goto LABEL_40;
    }
    v4 = operator new(0x1Cu);
    if ( v4 )
    {
      v5 = (_DWORD *)sub_4B1260(v4);
      *v5 = 1;
    }
    else
    {
      v5 = 0;
      MEMORY[0] = 1;
    }
LABEL_8:
    sub_578600(v12);
LABEL_31:
    if ( _strcmpi(String1, aClick) )
    {
      if ( _strcmpi(String1, aRelease) )
      {
        if ( _strcmpi(String1, aFocus) )
        {
          if ( !_strcmpi(String1, aLostfocus) )
            sub_49D030(a2, (int)v5);
        }
        else
        {
          sub_49CFF0(a2, (int)v5);
        }
      }
      else
      {
        sub_49CFB0(a2, (int)v5);
      }
    }
    else
    {
      sub_49CF70(a2, (int)v5);
    }
    goto LABEL_39;
  }
LABEL_40:
  --this[119];
  return 0;
}
