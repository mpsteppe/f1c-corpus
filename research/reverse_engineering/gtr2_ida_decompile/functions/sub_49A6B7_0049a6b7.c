void __userpurge sub_49A6B7(int a1@<ecx>, int a2@<esi>, int a3, char a4)
{
  int v5; // edi
  int v6; // [esp+8h] [ebp-3B4h] BYREF
  int v7; // [esp+Ch] [ebp-3B0h]
  float v8; // [esp+10h] [ebp-3ACh]
  _BYTE v9[4]; // [esp+44h] [ebp-378h] BYREF
  _BYTE v10[844]; // [esp+54h] [ebp-368h] BYREF
  int v11; // [esp+3B0h] [ebp-Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+3B8h] [ebp-4h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v6 = a2;
  sub_530770(v10, v6);
  HIBYTE(v7) = 0;
  sub_540150(&unk_BE1D30);
  if ( *(int *)dword_B640C8 > 0 && *(int *)dword_B640C8 <= 6 )
  {
    v8 = flt_FADE20 - flt_FADE1C;
    if ( v8 < dbl_FB1D18 )
      v8 = dbl_FB1D18;
  }
  sub_4DE580(0);
  v5 = v7;
  while ( (unsigned __int8)sub_5355A0((char *)&v6 + 3, v5) )
  {
    if ( HIBYTE(v6) )
      break;
    sub_4ED0E0();
    if ( a4 )
    {
      sub_4E0FF0(*(_DWORD *)(a1 + 48));
      sub_4DE260(1);
      sub_4E1520(1);
    }
  }
  if ( *(_DWORD *)dword_B640C8 == 6 && (unsigned __int8)sub_551D70(&unk_FADD40) )
  {
    sub_41E1E0();
    sub_4E1810(&v6, 0);
  }
  sub_4DE580(1);
  sub_4DE260(1);
  v11 = -1;
  nullsub_7(v9);
}
