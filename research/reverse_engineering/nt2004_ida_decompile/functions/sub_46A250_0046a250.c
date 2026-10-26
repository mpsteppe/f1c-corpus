char __thiscall sub_46A250(CHAR ****this)
{
  DWORD v2; // eax
  int *v3; // eax
  int v4; // eax
  CHAR ***v5; // eax
  HWND DlgItem; // eax
  char *v7; // eax
  char result; // al
  char v9; // [esp+7h] [ebp-D1h]
  char Source[92]; // [esp+8h] [ebp-D0h] BYREF
  char v11[4]; // [esp+64h] [ebp-74h] BYREF
  char Destination[112]; // [esp+68h] [ebp-70h] BYREF

  this[106] = (CHAR ***)((char *)this[106] + 1);
  v9 = 1;
  if ( hMutex && ((v2 = WaitForSingleObject(hMutex, dwMilliseconds)) == 0 || v2 == 128) )
    v3 = (int *)&unk_764EDC;
  else
    v3 = 0;
  v4 = *v3;
  if ( v4 == 3 || v4 == 4 )
  {
    v5 = this[105];
    if ( !v5 || v5 == (CHAR ***)4 )
      this[105] = (CHAR ***)7;
  }
  if ( hMutex )
    ReleaseMutex(hMutex);
  sub_4694C0((int)this);
  sub_469EB0(this, 0);
  switch ( (unsigned int)this[105] )
  {
    case 1u:
      this[105] = (CHAR ***)2;
      DlgItem = GetDlgItem(hWnd, 1034);
      SetWindowTextA(DlgItem, aBack);
      sub_462C80(Source);
      sub_462D30((int)Source);
      sub_462CE0(Source, 0, 1);
      v7 = (char *)sub_465260(dword_764D70, 0);
      if ( sub_463F30(dword_764D70, Source, v7) )
      {
        sub_462BC0(v11);
        strncpy(Destination, aServer_0, 0x1Fu);
        Destination[31] = 0;
        sub_463C20((int)v11);
        sub_46B260(this);
        nullsub_6(v11);
      }
      else
      {
        this[105] = (CHAR ***)7;
      }
      nullsub_6(Source);
      result = 1;
      break;
    case 2u:
      if ( sub_46A110(this) )
      {
        sub_4BA5F0(1);
        goto LABEL_20;
      }
      result = 1;
      this[105] = (CHAR ***)7;
      break;
    case 3u:
      unknown_libname_36();
LABEL_20:
      sub_4682F0(this + 148);
      result = 1;
      this[105] = (CHAR ***)4;
      break;
    case 4u:
      sub_467D20((int)(this + 148), (int)this);
      sub_4300E0(&dword_75CBA8);
      sub_469380((float *)this);
      result = 1;
      break;
    case 7u:
      if ( dword_75CBA8 != 2 )
        sub_4302B0(&dword_75CBA8);
      SendMessageA(dword_7652B4, 0x10u, 0, 0);
      v9 = 0;
      goto LABEL_27;
    default:
LABEL_27:
      result = v9;
      break;
  }
  return result;
}
