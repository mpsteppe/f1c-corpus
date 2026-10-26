char __thiscall sub_488580(void *this, char *String1, int a3, int a4)
{
  int v5; // esi
  int v7; // [esp-4h] [ebp-12Ch]
  char v8; // [esp+3h] [ebp-125h]
  char *String2; // [esp+14h] [ebp-114h]
  LPARAM lParam[4]; // [esp+18h] [ebp-110h] BYREF
  char v11; // [esp+28h] [ebp-100h]

  String2 = "/vote yes";
  lParam[0] = (LPARAM)"/vote no";
  lParam[1] = (LPARAM)"/callvote nextsession";
  lParam[2] = (LPARAM)"/callvote nextevent";
  lParam[3] = (LPARAM)"/callvote kickplayer ";
  v5 = 0;
  while ( _strnicmp(String1, (const char *)lParam[v5 - 1], strlen((const char *)lParam[v5 - 1])) )
  {
    if ( ++v5 >= 5 )
      goto LABEL_10;
  }
  switch ( v5 )
  {
    case 0:
    case 1:
      sub_4819E0();
      break;
    case 2:
      sub_487F70((int)this + 1056, 1, a4, -1);
      break;
    case 3:
      sub_487F70((int)this + 1056, 2, a4, -1);
      break;
    case 4:
      v7 = j__atol(String1 + 21);
      sub_487F70((int)this + 1056, 3, a4, v7);
      break;
    default:
      break;
  }
LABEL_10:
  v11 = 0;
  sub_472FE0();
  sub_47F220((LPARAM)lParam);
  return v8;
}
