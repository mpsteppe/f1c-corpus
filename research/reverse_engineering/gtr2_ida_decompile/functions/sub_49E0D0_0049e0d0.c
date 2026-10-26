int __thiscall sub_49E0D0(_DWORD *this)
{
  int result; // eax
  const CHAR *v3; // eax
  const CHAR *v4; // eax
  const char *v5; // eax
  const CHAR *v6; // eax
  double v7; // st7
  int v8; // edi
  unsigned __int64 v9; // rax
  double v10; // st7
  int v11; // ecx
  float v12; // [esp+0h] [ebp-240h]
  int v13; // [esp+4h] [ebp-23Ch] BYREF
  char v14; // [esp+8h] [ebp-238h] BYREF
  char v15[60]; // [esp+9h] [ebp-237h] BYREF
  __int16 v16; // [esp+45h] [ebp-1FBh]
  char v17; // [esp+47h] [ebp-1F9h]
  _BYTE v18[232]; // [esp+48h] [ebp-1F8h] BYREF
  float v19; // [esp+130h] [ebp-110h]
  char Buffer[260]; // [esp+13Ch] [ebp-104h] BYREF

  result = this[204];
  switch ( result )
  {
    case 475:
      v3 = (const CHAR *)dword_B73830;
      if ( !dword_B73830 )
        v3 = WindowName;
      return sub_4CE770(v3);
    case 476:
    case 501:
      result = sub_4735A0();
      if ( !(_BYTE)result )
        return result;
      v14 = 0;
      memset(v15, 0, sizeof(v15));
      v16 = 0;
      v17 = 0;
      sub_501490(&v14, 64);
      sub_4728E0();
      ((void (__thiscall *)(_DWORD *, unsigned int, char *, _BYTE *, int))byte_4CE840)(
        this,
        159 - strlen(&v15[51]),
        &v14,
        v18,
        128);
LABEL_4:
      result = (*(int (__thiscall **)(_DWORD *))(*this + 132))(this);
      break;
    case 481:
      v14 = 0;
      memset(v15, 0, sizeof(v15));
      v16 = 0;
      v17 = 0;
      sub_501490(&v14, 64);
      v13 = 0;
      if ( (unsigned __int8)sub_52A140(&unk_BE1210, v18) )
        v7 = v19;
      else
        v7 = v12;
      v8 = (unsigned __int64)(0.016666668 * v7);
      v9 = (unsigned __int64)v7;
      v10 = (v7 - (double)(int)(unsigned __int64)v7) * 1000.0;
      v11 = (unsigned __int64)v10;
      if ( v10 - (double)v11 > 0.5 )
        ++v11;
      sprintf(Buffer, "%s - %01d_%02d_%03d", (const char *)&v13, v8, (int)v9 % 60, v11);
      return sub_4CE770(Buffer);
    case 482:
      result = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)this[12] + 28))(this[12], 53);
      if ( result )
      {
        result = sub_4CE170(result);
        if ( result )
        {
          sprintf(Buffer, "%s", (const char *)result);
          return sub_4CE770(Buffer);
        }
      }
      return result;
    case 486:
    case 487:
    case 488:
    case 489:
    case 490:
    case 491:
    case 492:
    case 493:
    case 494:
    case 495:
      v3 = (const CHAR *)dword_B6F7B4[7 * result - 3402];
      if ( v3 )
        return sub_4CE770(v3);
      else
        return sub_4CE770(WindowName);
    case 496:
      goto LABEL_4;
    case 497:
      v4 = (const CHAR *)dword_B73868;
      if ( !dword_B73868 )
        v4 = WindowName;
      sub_4CE770(v4);
      v5 = (const char *)dword_B73868;
      if ( !dword_B73868 )
        v5 = WindowName;
      goto LABEL_14;
    case 498:
      v6 = (const CHAR *)dword_B73884;
      if ( !dword_B73884 )
        v6 = WindowName;
      sub_4CE770(v6);
      v5 = (const char *)dword_B73884;
      if ( !dword_B73884 )
        v5 = WindowName;
LABEL_14:
      result = strlen(v5);
      v13 = result;
      if ( !result )
        result = (*(int (__thiscall **)(_DWORD *))(*this + 132))(this);
      break;
    default:
      return result;
  }
  return result;
}
