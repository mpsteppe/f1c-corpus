char __thiscall sub_480D90(void *this)
{
  int v2; // eax
  const char *v3; // ebx
  unsigned int v4; // kr04_4
  size_t v5; // esi
  float v7; // [esp+0h] [ebp-1A8h]
  char v8[64]; // [esp+18h] [ebp-190h] BYREF
  char Source[125]; // [esp+58h] [ebp-150h] BYREF
  __int16 v10; // [esp+D5h] [ebp-D3h]
  char v11; // [esp+D7h] [ebp-D1h]
  _BYTE v12[8]; // [esp+D8h] [ebp-D0h] BYREF
  char Destination[200]; // [esp+E0h] [ebp-C8h] BYREF

  v2 = *((_DWORD *)this + 204);
  switch ( v2 )
  {
    case 542:
      LOBYTE(v2) = (unsigned __int8)strncpy(&byte_765490, *((const char **)this + 199), 0x17u);
      byte_7654A7 = 0;
      break;
    case 546:
      LOBYTE(v2) = (unsigned __int8)strncpy(byte_765518, *((const char **)this + 199), 0x3Fu);
      byte_765557 = 0;
      break;
    case 547:
      LOBYTE(v2) = sub_463490(dword_764D70);
      if ( (_BYTE)v2 )
      {
        v3 = (const char *)*((_DWORD *)this + 199);
        if ( v3 )
        {
          v4 = strlen(v3) + 1;
          v5 = v4 - 1;
          if ( (int)(v4 - 1) > 0 )
          {
            if ( (int)(v4 - 1) > 127 )
              v5 = 127;
            v7 = dbl_7DA9D0;
            sub_4D0D00(4, 6, v5, 0, LODWORD(v7), 3);
            strncpy(Destination, v3, v5);
            Destination[v5] = 0;
            sub_463A40(dword_764D70, (int)v12, 0, -1, -1);
            Source[0] = byte_629120;
            memset(&Source[1], 0, 0x7Cu);
            v10 = 0;
            v11 = 0;
            v8[0] = byte_629120;
            memset(&v8[1], 0, 63);
            sub_4CE010(v8, 64);
            sub_45D040(v8, Destination, Source, 128);
            sub_4BA6B0(Source);
          }
        }
        LOBYTE(v2) = (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 160))(this, 1);
      }
      break;
    case 551:
    case 552:
    case 553:
    case 554:
    case 555:
    case 556:
    case 557:
    case 558:
    case 559:
    case 560:
    case 561:
    case 562:
      LOBYTE(v2) = sub_578600(*((_DWORD *)this + 199));
      break;
    default:
      return v2;
  }
  return v2;
}
