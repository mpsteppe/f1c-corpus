const char *__thiscall sub_45D570(int this, LPCSTR lpFileName, char *Str, int a4)
{
  const char *result; // eax
  char v6; // al
  char *v7; // edi
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  int v10; // ebp
  _DWORD *v11; // eax
  int v12; // [esp+10h] [ebp-204h] BYREF
  char Buffer[512]; // [esp+14h] [ebp-200h] BYREF

  sub_578A30(lpFileName, 1, Str, 1);
  sub_578A00(&unk_7D7A0C);
  for ( result = (const char *)sub_578D80(&unk_7D7A0C); result; result = (const char *)sub_578D80(&unk_7D7A0C) )
  {
    sprintf(Buffer, "%s%s", Str, result);
    switch ( a4 )
    {
      case 1:
        v6 = sub_45D8D0(Buffer, (int)&v12, 0);
        break;
      case 2:
        v6 = sub_45DB30(Buffer, &v12);
        break;
      case 3:
        v6 = sub_45DBD0(Buffer, (int)&v12);
        break;
      default:
        v6 = sub_57B490(Buffer, *(unsigned __int8 *)(this + 1), (int)&v12);
        break;
    }
    if ( v6 )
    {
      v7 = &Buffer[strlen(Buffer)];
      if ( v7 > Buffer )
      {
        while ( *v7 != 92 )
        {
          if ( --v7 <= Buffer )
            goto LABEL_15;
        }
        ++v7;
      }
LABEL_15:
      v8 = operator new(0xCu);
      v9 = v8;
      if ( v8 )
      {
        v10 = v12;
        *v8 = 0;
        v8[1] = -1;
        sub_578600(v7);
        v9[2] = v10;
      }
      else
      {
        v9 = 0;
      }
      if ( v9 )
      {
        v11 = operator new(0xCu);
        if ( v11 )
        {
          *v11 = v9;
          v11[1] = 0;
          *((_BYTE *)v11 + 8) = 1;
        }
        else
        {
          v11 = 0;
        }
        if ( *(_DWORD *)(this + 4) )
        {
          *(_DWORD *)(*(_DWORD *)(this + 8) + 4) = v11;
        }
        else
        {
          *(_DWORD *)(this + 4) = v11;
          *(_DWORD *)(this + 12) = v11;
        }
        *(_DWORD *)(this + 8) = v11;
        ++*(_DWORD *)(this + 16);
      }
    }
    result = (const char *)sub_5789D0(&unk_7D7A0C);
    if ( !(_BYTE)result )
      break;
  }
  return result;
}
