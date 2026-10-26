int __stdcall sub_49E520(int a1)
{
  double v1; // st7

  v1 = dbl_8AFEA0;
  InterruptDispatch(dbl_8AFEA0);
  if ( v1 <= 0.5 )
    return AudioEffectTrigger(0, a1);
  else
    return AudioEffectTrigger(1, a1);
}

