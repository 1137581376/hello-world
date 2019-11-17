; ModuleID = 'int.c'
source_filename = "int.c"
target datalayout = "e-m:e-p:16:16-i32:16-i64:16-f32:16-f64:16-a:8-n8:16-S16"
target triple = "msp430"

; Function Attrs: noinline nounwind optnone
define dso_local i16 @add(i16, ...) #0 {
  %2 = alloca i16, align 2
  %3 = alloca i8*, align 2
  %4 = alloca i16, align 2
  %5 = alloca i16, align 2
  %6 = alloca i16, align 2
  store i16 %0, i16* %2, align 2
  %7 = bitcast i8** %3 to i8*
  call void @llvm.va_start(i8* %7)
  store i16 0, i16* %4, align 2
  store i16 0, i16* %5, align 2
  br label %8

; <label>:8:                                      ; preds = %17, %1
  %9 = load i16, i16* %5, align 2
  %10 = load i16, i16* %2, align 2
  %11 = icmp slt i16 %9, %10
  br i1 %11, label %12, label %20

; <label>:12:                                     ; preds = %8
  %13 = va_arg i8** %3, i16
  store i16 %13, i16* %6, align 2
  %14 = load i16, i16* %6, align 2
  %15 = load i16, i16* %4, align 2
  %16 = add nsw i16 %15, %14
  store i16 %16, i16* %4, align 2
  br label %17

; <label>:17:                                     ; preds = %12
  %18 = load i16, i16* %5, align 2
  %19 = add nsw i16 %18, 1
  store i16 %19, i16* %5, align 2
  br label %8

; <label>:20:                                     ; preds = %8
  %21 = load i16, i16* %4, align 2
  ret i16 %21
}

; Function Attrs: nounwind
declare void @llvm.va_start(i8*) #1

attributes #0 = { noinline nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 2}
!1 = !{!"clang version 7.0.0 (tags/RELEASE_700/final)"}
