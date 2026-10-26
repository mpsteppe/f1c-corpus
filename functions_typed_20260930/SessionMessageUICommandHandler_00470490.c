int __thiscall sub_470490(void *this)
{
  int result; // eax
  int v3; // ebx
  unsigned int v4; // kr04_4
  int v5; // esi
  float v6; // [esp+0h] [ebp-308h]
  char v7[61]; // [esp+18h] [ebp-2F0h] BYREF
  __int16 v8; // [esp+55h] [ebp-2B3h]
  char v9; // [esp+57h] [ebp-2B1h]
  _BYTE v10[253]; // [esp+58h] [ebp-2B0h] BYREF
  __int16 v11; // [esp+155h] [ebp-1B3h]
  char v12; // [esp+157h] [ebp-1B1h]
  int v13; // [esp+158h] [ebp-1B0h] BYREF
  char v14[424]; // [esp+160h] [ebp-1A8h] BYREF

  if ( *((_DWORD *)this + 193) == 432 )
  {
    result = sub_587DD0(&byte_7CD834, *((_DWORD *)this + 188), 25);
    byte_7CD84D = 0;
  }
  else if ( *((_DWORD *)this + 193) == 434 )
  {
    result = sub_587DD0(&unk_7CD860, *((_DWORD *)this + 188), 31);
    byte_7CD87F = 0;
  }
  else
  {
    result = *((_DWORD *)this + 193) - 435;
    if ( *((_DWORD *)this + 193) == 435 )
    {
      if ( SessionStateCheckWrapper(dword_7CD25C) && (void *)FieldGetter_79d0(*((_DWORD *)this + 16)) == this )
      {
        v3 = *((_DWORD *)this + 188);
        if ( v3 )
        {
          v4 = strlen(*((const char **)this + 188)) + 1;
          v5 = v4 - 1;
          if ( (int)(v4 - 1) > 0 )
          {
            if ( (int)(v4 - 1) > 159 )
              v5 = 159;
            v6 = dbl_8AFEA0;
            ProgressBarEventEncode(4, 6, v5, 0, LODWORD(v6), 1);
            sub_587DD0(v14, v3, v5);
            v14[v5] = 0;
            TextureCreationWrapper(dword_7CD25C, &v13, 0, -1, -1);
            v10[0] = byte_5EA438[0];
            memset(&v10[1], 0, 0xFCu);
            v11 = 0;
            v12 = 0;
            v7[0] = byte_5EA438[0];
            memset(&v7[1], 0, 0x3Cu);
            v8 = 0;
            v9 = 0;
            sub_4B0B20(v7, 64);
            StringCopyWithFormatQuery(v7, v14, v10, 256);
            SessionStateDispatch(v10);
          }
        }
      }
      return (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 168))(this, 1);
    }
  }
  return result;
}

