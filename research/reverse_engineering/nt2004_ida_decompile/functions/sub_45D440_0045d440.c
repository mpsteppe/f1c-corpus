int __fastcall sub_45D440(int a1, int a2, int a3, int a4)
{
  const char *v5; // [esp-8h] [ebp-58h]
  int v6; // [esp-4h] [ebp-54h]
  int v7; // [esp-4h] [ebp-54h]
  int v8; // [esp-4h] [ebp-54h]
  char Source[80]; // [esp+0h] [ebp-50h] BYREF

  Source[0] = 0;
  byte_764DC4 = 1;
  switch ( a2 )
  {
    case 0:
      v6 = sub_5BA200(a3, *(_DWORD *)Source);
      sprintf(Source, "Added %s", v6);
      break;
    case 1:
      v7 = sub_5BA160(aNone_3);
      sprintf(Source, "Updated %s", v7);
      break;
    case 2:
      v8 = sub_5BA200(a3, *(_DWORD *)Source);
      v5 = aCouldnTUpdateS;
      goto LABEL_8;
    case 3:
      sprintf(Source, aServerDeletedF);
      break;
    case 4:
      sprintf(Source, aUpdateComplete);
      break;
    case 5:
      v8 = sub_5B9F80(*(_DWORD *)Source);
      v5 = aQueryErrorS;
LABEL_8:
      sprintf(Source, v5, v8);
      break;
    default:
      break;
  }
  if ( sub_41F230(dword_62A170, Source, Destination) )
  {
    strncpy(Destination, Source, 0x1FFu);
    byte_62A37B = 0;
  }
  return sub_464BC0(Destination);
}
