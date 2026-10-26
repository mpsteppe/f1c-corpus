// f1c  0x00408740  size=154
int __thiscall sub_408740(float *this, float a2)
{
  float v2; // edi
  int v4; // ecx
  int result; // eax
  int v6; // [esp+0h] [ebp-18h]
  float v7; // [esp+4h] [ebp-14h]
  float v8; // [esp+14h] [ebp-4h] BYREF

  v2 = a2;
  switch ( LODWORD(a2) )
  {
    case 0:
      v4 = *((_DWORD *)this + 4);
      goto LABEL_11;
    case 1:
      v4 = *((_DWORD *)this + 5);
      goto LABEL_11;
    case 2:
      v4 = *((_DWORD *)this + 6);
      goto LABEL_11;
    case 3:
      v4 = *((_DWORD *)this + 7);
      goto LABEL_11;
    case 4:
      result = *((_DWORD *)this + 8);
      v4 = result + 200 * *((_DWORD *)this + 15);
      goto LABEL_11;
    case 5:
      v4 = *((_DWORD *)this + 9);
      goto LABEL_11;
    case 6:
      v4 = *((_DWORD *)this + 10);
      goto LABEL_11;
    case 7:
      v4 = *((_DWORD *)this + 11);
      goto LABEL_11;
    case 8:
      v4 = *((_DWORD *)this + 12);
LABEL_11:
      if ( v4 )
      {
        result = *((_DWORD *)this + 1);
        if ( result )
        {
          sub_456060(&v8, &a2);
          v7 = a2 * 0.01745433;
          *(float *)&v6 = v8 * 0.01745433;
          result = sub_542050(v6, v7, 0);
          this[13] = v2;
        }
      }
      break;
    default:
      return result;
  }
  return result;
}
