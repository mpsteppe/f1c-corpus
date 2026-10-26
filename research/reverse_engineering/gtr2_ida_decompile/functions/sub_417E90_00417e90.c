char __thiscall sub_417E90(_DWORD *this, int a2, char a3)
{
  unsigned int v4; // edx
  int v5; // ecx
  char result; // al
  _BYTE v7[4]; // [esp+8h] [ebp-18h] BYREF
  _BYTE v8[4]; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v9[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v10[4]; // [esp+14h] [ebp-Ch] BYREF
  _BYTE v11[4]; // [esp+18h] [ebp-8h] BYREF
  _BYTE v12[4]; // [esp+1Ch] [ebp-4h] BYREF

  sub_5EDA00(0, 0);
  v4 = this[8];
  if ( v4 <= 2 )
    sub_4179B0(a2, v4);
  sub_5DA610(v10, v11, v12, v7, v8, v9);
  switch ( this[8] )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      v5 = this[9];
      *(_DWORD *)(v5 + 216) = a2;
      (**(void (__thiscall ***)(int))v5)(v5);
      sub_4167F0();
      break;
    default:
      break;
  }
  sub_4168A0((int)this);
  result = a3;
  if ( !a3 )
    return sub_52FC50(this);
  return result;
}
