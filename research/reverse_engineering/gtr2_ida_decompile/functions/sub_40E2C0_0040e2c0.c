int __thiscall sub_40E2C0(_DWORD *this, int a2)
{
  int v2; // edi
  int v4; // ecx
  int result; // eax
  int v6; // [esp+0h] [ebp-20h]
  float v7; // [esp+4h] [ebp-1Ch]
  float v8; // [esp+14h] [ebp-Ch]
  float v9; // [esp+1Ch] [ebp-4h] BYREF

  v2 = a2;
  switch ( a2 )
  {
    case 0:
      v4 = this[4];
      goto LABEL_11;
    case 1:
      v4 = this[5];
      goto LABEL_11;
    case 2:
      v4 = this[6];
      goto LABEL_11;
    case 3:
      v4 = this[7];
      goto LABEL_11;
    case 4:
      result = this[8];
      v4 = result + 204 * this[15];
      goto LABEL_11;
    case 5:
      v4 = this[9];
      goto LABEL_11;
    case 6:
      v4 = this[10];
      goto LABEL_11;
    case 7:
      v4 = this[11];
      goto LABEL_11;
    case 8:
      v4 = this[12];
LABEL_11:
      if ( v4 )
      {
        result = this[1];
        if ( result )
        {
          sub_46B1F0(&v9, &a2);
          v7 = v9 * 0.01745433;
          *(float *)&v6 = v8 * 0.01745433;
          result = sub_5E5240(v6, v7, 0);
          this[13] = v2;
        }
      }
      break;
    default:
      return result;
  }
  return result;
}
