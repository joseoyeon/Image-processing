# Image-processing


## 4-1 영상처리

![image](https://user-images.githubusercontent.com/46625602/84286064-2cd88000-ab79-11ea-88b0-4f1bb8bce6d0.png)

# Image 
![image](https://user-images.githubusercontent.com/46625602/84286275-70cb8500-ab79-11ea-89d1-396ea21bd4cf.png)

**덧셈(Addition)**
위 그림은 노이즈가 첨가된 영상과, 원본 영상, 노이즈간의 관계를 나타낸 식이다. 식의 의미를 살펴보면 이렇다. 노이즈가 낀 영상들의 평균은 원본 영상이라는 것이다. 다만, 이 경우 노이즈가 낀 영상이 1개, 2개 있다고 해서 되는 것이 아니고, 수 많은 노이즈가 낀 영상들이 필요하다. 그렇게 되면, 노이즈끼리의 상충작용이 일어나서, 원본영상에 가까워 진다는 것이다. 그리고 노이즈가 낀 영상들의 평균은 원본영상 이었으므로, 당연히, 노이즈가 낀 영상들은, 원본영상을 중심으로 노이즈만큼 차이가 날테니까, 노이즈가낀 영상들의 분산은 노이즈들의 분산들과 같다는 것을 알 수 있다. 이렇게, 노이즈가낀 영상들 수십, 수백개를 평균내어서, 노이즈가 없는 원본영상을 찾으려고 하는 과정을 `영상 평균화(image averaging)` 이라 한다. 다음 그림은 영상평균화의 예시를 나타낸다.

---

**참고 자료**


* [1] [https://sunshower76.github.io/cv(computervision)/2019/08/26/Digital-Image-Processing-Digital-image-fundamentals_4-(chapter-2)/](https://sunshower76.github.io/cv(computervision)/2019/08/26/Digital-Image-Processing-Digital-image-fundamentals_4-(chapter-2)/)

* [2] [https://nauco.tistory.com/5](https://nauco.tistory.com/5)

* [3] [https://webnautes.tistory.com/1043](https://webnautes.tistory.com/1043)

* [4] [Visual Studio Github 연동](https://www.smoh.kr/269)
