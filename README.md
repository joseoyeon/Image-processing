# Image-processing


## 4-1 영상처리

![image](https://user-images.githubusercontent.com/46625602/84286064-2cd88000-ab79-11ea-88b0-4f1bb8bce6d0.png)

# Image 
![image](https://user-images.githubusercontent.com/46625602/84286275-70cb8500-ab79-11ea-89d1-396ea21bd4cf.png)

**덧셈(Addition)**


위 그림은 노이즈가 첨가된 영상과, 원본 영상, 노이즈간의 관계를 나타낸 식이다. 식의 의미를 살펴보면 이렇다. 노이즈가 낀 영상들의 평균은 원본 영상이라는 것이다. 다만, 이 경우 노이즈가 낀 영상이 1개, 2개 있다고 해서 되는 것이 아니고, 수 많은 노이즈가 낀 영상들이 필요하다. 그렇게 되면, 노이즈끼리의 상충작용이 일어나서, 원본영상에 가까워 진다는 것이다. 그리고 노이즈가 낀 영상들의 평균은 원본영상 이었으므로, 당연히, 노이즈가 낀 영상들은, 원본영상을 중심으로 노이즈만큼 차이가 날테니까, 노이즈가낀 영상들의 분산은 노이즈들의 분산들과 같다는 것을 알 수 있다. 이렇게, 노이즈가낀 영상들 수십, 수백개를 평균내어서, 노이즈가 없는 원본영상을 찾으려고 하는 과정을 `영상 평균화(image averaging)` 이라 한다. 다음 그림은 영상평균화의 예시를 나타낸다.

# Histogram Equalization 

![image](https://user-images.githubusercontent.com/46625602/85947045-5e2bbb00-b983-11ea-89a8-3a5a880eaafc.png)

히스토그램 평준화 알고리즘은 흑백 이미지의 Intensity를 높여 이미지의 대비효과를 준다.

![image](https://user-images.githubusercontent.com/46625602/85947056-6e439a80-b983-11ea-9e36-6bafee404838.png)

다음과 같은 식을 가지고 평준화를 하며 식의 내용은 r강도를 가진 픽셀의 개수를 누적합한 것에 (L-1)/MN(size)라는 상수를 곱한 것이 Sk가 된다는 것이다 여기서 Sk는 명암 대비 보정을 시켜준 새로운 이미지 r강도를 가진 픽셀의 개수가 된다. 핵심 코드는 다음과 같다.

![image](https://user-images.githubusercontent.com/46625602/85947066-7996c600-b983-11ea-8805-39869a11c4f7.png)


![image](https://user-images.githubusercontent.com/46625602/85947075-84515b00-b983-11ea-895d-d07ee0660f85.png)
![image](https://user-images.githubusercontent.com/46625602/85947077-85828800-b983-11ea-9d9b-61a614d9b2f5.png)


# Histogram Matching

입력 이미지가 타겟 이미지의 히스토그램을 갖도록 histogram matching을 수행한 결과 이미지

![image](https://user-images.githubusercontent.com/46625602/85947083-9206e080-b983-11ea-8bbf-7c5165f85e9c.png)

각 intensity 마다의 pixel들을 count를 해주는 imhist 함수

![image](https://user-images.githubusercontent.com/46625602/85947084-93380d80-b983-11ea-86cc-297875fb22af.png)

Sumhist로 histogram 분포를 구한다

![image](https://user-images.githubusercontent.com/46625602/85947089-a64add80-b983-11ea-95ca-09378d95516f.png)
![image](https://user-images.githubusercontent.com/46625602/85947095-b498f980-b983-11ea-9870-fa24a5f2eb50.png)


왼쪽 그림은 원본 이미지, 오른쪽 그림은 결과 이미지이다. Target 이미지는 그 아래 이미지와 같고,


원본 이미지에서는 명암이 높아 보이지 않던 부분이 target 이미지를 가지고 image matching후에는 윤곽이 뚜렷해진 것을 확인 할 수 있다.


![image](https://user-images.githubusercontent.com/46625602/85947104-c37fac00-b983-11ea-9d41-209d52d7eb65.png)
![image](https://user-images.githubusercontent.com/46625602/85947105-c5496f80-b983-11ea-86c2-e6c0fae67796.png)
![image](https://user-images.githubusercontent.com/46625602/85947106-c67a9c80-b983-11ea-8fd6-019ae0952756.png)


---

**참고 자료**


* [1] [https://sunshower76.github.io/cv(computervision)/2019/08/26/Digital-Image-Processing-Digital-image-fundamentals_4-(chapter-2)/](https://sunshower76.github.io/cv(computervision)/2019/08/26/Digital-Image-Processing-Digital-image-fundamentals_4-(chapter-2)/)

* [2] [https://nauco.tistory.com/5](https://nauco.tistory.com/5)

* [3] [https://webnautes.tistory.com/1043](https://webnautes.tistory.com/1043)

* [4] [Visual Studio Github 연동](https://www.smoh.kr/269)
