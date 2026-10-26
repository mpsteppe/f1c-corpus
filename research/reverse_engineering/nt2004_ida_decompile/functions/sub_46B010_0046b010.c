char __thiscall sub_46B010(_DWORD *this, char *String1, const char *a3, int a4)
{
  int v5; // esi
  char v7; // [esp+13h] [ebp-111h]
  char *String2[4]; // [esp+14h] [ebp-110h]
  char Destination[256]; // [esp+24h] [ebp-100h] BYREF

  v7 = 0;
  String2[0] = aVoteYes;
  String2[1] = aVoteNo;
  String2[2] = aCallvoteNextse;
  String2[3] = aCallvoteNextev;
  v5 = 0;
  while ( _strnicmp(String1, String2[v5], strlen(String2[v5])) )
  {
    if ( ++v5 >= 4 )
      goto LABEL_10;
  }
  v7 = 1;
  switch ( v5 )
  {
    case 0:
      sub_467E40(this + 148, a4, 1, 0);
      break;
    case 1:
      sub_467E40(this + 148, a4, 0, 0);
      break;
    case 2:
      sub_468080((int)(this + 148), 1, a4);
      break;
    case 3:
      sub_468080((int)(this + 148), 2, a4);
      break;
    default:
      break;
  }
LABEL_10:
  Destination[0] = 0;
  sub_45D040(a3, String1, Destination, 256);
  sub_46B130((LPARAM)Destination);
  return v7;
}
