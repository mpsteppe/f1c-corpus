// Address: 0x00494c15
// Size: 11 bytes
// Name: sub_494C15
// Type: HGDIOBJ __userpurge@<eax>(char@<bl>, int@<edi>, int, int, int, int, int, int, int, int, int, int)
// Source: IDA Hex-Rays decompilation

HGDIOBJ __userpurge sub_494C15@<eax>(
        char a1@<bl>,
        int a2@<edi>,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12)
{
  *(_BYTE *)(a2 + 94) += a1;
  return GetStockObject((unsigned __int16)__ES__);
}
