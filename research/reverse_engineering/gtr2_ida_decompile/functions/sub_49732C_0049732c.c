int sub_49732C(
        int a1,
        __int128 a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        __int128 a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        ...)
{
  int v43; // ecx
  int v44; // ebp
  int v45; // eax
  char *v46; // eax
  int i; // esi
  const char *v48; // eax
  int v50; // [esp+0h] [ebp-10h]
  va_list va; // [esp+D8h] [ebp+C8h] BYREF

  va_start(va, a43);
  v44 = v43;
  LOBYTE(a2) = 0;
  memset((char *)&a2 + 1, 0, 0x3Cu);
  *(_WORD *)((char *)&a14 + 1) = 0;
  HIBYTE(a14) = 0;
  v45 = sub_4CE170(v43);
  *(_BYTE *)(v44 + 524) = 0;
  if ( v45 )
  {
    sub_630FE0(&a2, v45, 63);
    HIBYTE(a14) = 0;
  }
  sub_4D0AC0(v50);
  sub_615FC0(&unk_FAECBC);
  v46 = *(char **)dword_BE121C;
  if ( !*(_DWORD *)dword_BE121C )
    v46 = (char *)WindowName;
  sub_615FE0("*.GTT", 1, v46, 0);
  sub_615F10(0);
  sub_615D10(&unk_FAECBC);
  for ( i = sub_615CC0(&unk_FAECBC); i; i = sub_615CC0(&unk_FAECBC) )
  {
    v48 = *(const char **)dword_BE121C;
    if ( !*(_DWORD *)dword_BE121C )
      v48 = WindowName;
    sprintf(va, "%s%s", v48, (const char *)(i + 44));
    if ( (unsigned __int8)sub_523C20(va) )
    {
      LOBYTE(a15) = 0;
      memset((char *)&a15 + 1, 0, 0x7Cu);
      *(_WORD *)((char *)&a43 + 1) = 0;
      HIBYTE(a43) = 0;
      sub_4972A0((char *)i, (char *)&a15);
      if ( strlen((const char *)&a15) )
        sub_4D93B0(&a15, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    }
    sub_615CE0(&unk_FAECBC);
  }
  sub_4D4150(v44, &a2);
  return sub_615FC0(&unk_FAECBC);
}
